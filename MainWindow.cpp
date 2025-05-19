#include <QStandardPaths>
#include <QDir>

#include "MainWindow.h"
#include "ui_LoginPage.h"
#include "ui_MainWindow.h"
#include "ui_MainPage.h"
#include "ui_AboutPage.h"
#include "ui_HelpPage.h"
#include "ui_DatabasePage.h"
#include "ui_TestPage.h"

#include <QAudioDevice>
#include <QMediaFormat>
#include <QFile>
#include <QDir>
#include <QNetworkRequest>
#include <QHttpMultiPart>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QNetworkReply>
#include <QTimer>
#include <QPushButton>

int curminor=0;     //current test inside the test file (1-29/1-10)
int curmajor=1;     //test file number (1-3)
int curansw=0;      //correct answers for current test
int answer1=0;      //total correct answers for test 1/2/3
int answer2=0;
int answer3=0;

QString username;   //current registered user
QString testPath;

QTextStream stream;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    loginPage = new QWidget();
    mainPage = new QWidget();
    aboutPage = new QWidget();
    helpPage = new QWidget();
    databasePage = new QWidget();
    testPage = new QWidget();
    Ui::LoginPage loginUi;
    Ui::MainPage mainUi;
    Ui::AboutPage aboutUi;
    Ui::HelpPage helpUi;
    Ui::DatabasePage databaseUi;
    Ui::TestPage testUi;
    loginUi.setupUi(loginPage);
    mainUi.setupUi(mainPage);
    aboutUi.setupUi(aboutPage);
    helpUi.setupUi(helpPage);
    databaseUi.setupUi(databasePage);
    testUi.setupUi(testPage);

    // Setup audio capture
    m_audioInput = new QAudioInput(this);
    m_captureSession.setAudioInput(m_audioInput);

    m_mediaRecorder = new QMediaRecorder(this);
    m_captureSession.setRecorder(m_mediaRecorder);

    QMediaFormat format;
    format.setFileFormat(QMediaFormat::Wave);               //wave is the standard, but mp3 also works
    format.setAudioCodec(QMediaFormat::AudioCodec::Wave);
    m_mediaRecorder->setMediaFormat(format);

    // Add pages to QStackedWidget
    ui->stackedWidget->addWidget(mainPage);     //0
    ui->stackedWidget->addWidget(loginPage);    //1
    ui->stackedWidget->addWidget(aboutPage);    //2
    ui->stackedWidget->addWidget(helpPage);     //3
    ui->stackedWidget->addWidget(databasePage); //4
    ui->stackedWidget->addWidget(testPage);     //5
    // Connect buttons to switch pages
    QObject::connect(loginUi.btnGoToMain, &QPushButton::clicked,    //Go to Main
                     this, &MainWindow::registerUser);
    QObject::connect(aboutUi.btnGoToMain, &QPushButton::clicked,    //Go to Main
                     this, &MainWindow::switchToMainPage);
    QObject::connect(helpUi.btnGoToMain, &QPushButton::clicked,     //Go to Main
                     this, &MainWindow::switchToMainPage);
    QObject::connect(databaseUi.btnGoToMain, &QPushButton::clicked, //Go to Main
                     this, &MainWindow::switchToMainPage);
    QObject::connect(mainUi.btnregister, &QPushButton::clicked,     //Register
                     this, &MainWindow::switchToRegisterPage);
    QObject::connect(mainUi.btnabout, &QPushButton::clicked,        //About
                     this, &MainWindow::switchToAboutPage);
    QObject::connect(mainUi.btnhelp, &QPushButton::clicked,         //Help
                     this, &MainWindow::switchToHelpPage);
    QObject::connect(mainUi.btndatabase, &QPushButton::clicked,     //Database
                     this, &MainWindow::switchToDatabasePage);
    QObject::connect(mainUi.btntest, &QPushButton::clicked,         //Test
                     this, &MainWindow::switchToTestPage);
    QObject::connect(testUi.btnVerno, &QPushButton::clicked,        //Test
                     this, &MainWindow::correctAnswer);
    QObject::connect(testUi.btnNeverno, &QPushButton::clicked,      //Test
                     this, &MainWindow::wrongAnswer);
    QObject::connect(testUi.recordButton, &QPushButton::clicked,    //Test
                     this, &MainWindow::on_recordButton_clicked);
}

MainWindow::~MainWindow() {
    delete ui;
    delete loginPage;
    delete mainPage;
    delete aboutPage;
    delete databasePage;
    delete testPage;
}
void MainWindow::registerUser() {                                                       //Registration
    QTextEdit *txtUsername = loginPage->findChild<QTextEdit*>("nameEdit");
    if (txtUsername) {
        username = txtUsername->toPlainText().trimmed();
    }
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::switchToDatabasePage(){
    ui->stackedWidget->setCurrentIndex(4);
    QListWidget *listUsers = databasePage->findChild<QListWidget*>("listWidget");        //get imaging widget
    listUsers->clear();
    QString logDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation); //set path to file
    QDir dir(logDir);
    if (!dir.exists() && !dir.mkpath(".")) {
        QMessageBox::warning(this, "Error", "Failed to create log directory!");
        return;
    }
    QString isend;                                              //database structure:
    bool flag=true;                                             //(Name) (Test1 correct answers) (Test2 correct answ.) (Test3 correct answ.)
    QString logPath = logDir + "/Database.txt";                 //... each line represents a user
    QFile file(logPath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {     //if the file was successfully opened
        QTextStream stream(&file);
        while (flag==true){
                isend=stream.readLine(0);                       //read full line
            if (isend.isNull()==true){                          //if the line is empty, (database is empty or has been fully read) exit loop
                    flag=false;
            } else{
                listUsers->addItem(isend);
            }
            }
        file.close();
    }
}

void MainWindow::switchToTestPage(){
    if (username.isNull()){
        QMessageBox::warning(this, "Error", "No user registered");  //requires a user to be registered
    }
    else{
        ui->stackedWidget->setCurrentIndex(5);
        updateFunction();
    }
}

void MainWindow::updateFunction(){
    curminor++;
    if ((curmajor==1)&(curminor>28)){
        curmajor=2;
        answer1=curansw;
        curansw=0;
        curminor=0;
    }
    if ((curmajor==2)&(curminor>28)){
        curmajor=3;
        answer2=curansw;
        curansw=0;
        curminor=0;
    }
    if ((curmajor==3)&(curminor>9)){
        curmajor=0;
        answer3=curansw;
        curansw=0;
        curminor=0;
        writeResults();
    }
    if (curmajor==1){
        testPath =":/new/prefix1/test1.txt";
    }
    if (curmajor==2){
        testPath =":/new/prefix1/test2.txt";
    }
    if (curmajor==3){
        testPath =":/new/prefix1/test3.txt";
    }
    QLabel *testText = testPage->findChild<QLabel*>("labelZadanie");
    QFile file(testPath);
    QString isend;
    if ((curminor==1)&(curmajor==1)){
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            isend=stream.readLine(0);
            testText->setText(isend);
        }
    }else{
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            isend=stream.readLine(2);       //read the current minor test number
            bool ok;
            bool flag=true;
            int num = isend.toInt(&ok);
            // curm = QString::number(curminor);
            while (flag==true){
                if (num==curminor){         //if the current (shown) test's number is equal to the test number of the test file
                    if ((((curmajor==1)|(curmajor==2))&(curminor==29))){
                        //QMessageBox::warning(this, "isend is: ", "");
                        isend=stream.readLine(0);       //read the remaining contents of the line (the actual test text)
                        testText->setText(isend);       //send it to the UI
                    }
                    flag=false;                         //and exit the loop
                }
                else{
                    //QMessageBox::warning(this, "isend is: ", isend);
                    //QMessageBox::warning(this, "curminor is ", curm);
                    isend=stream.readLine(0);       //else, read the remaining contents
                    isend=stream.readLine(2);       //and then read the number of the next line and return to the loop's beginning
                    num = isend.toInt(&ok);
                }
            }
            isend=stream.readLine(0);
            testText->setText(isend);
        }
    }

}

void MainWindow::writeResults(){
    ui->stackedWidget->setCurrentIndex(0);      //switch to main menu
    curmajor=1;        //make sure you are able to begin the test again from the beginning
    curminor=0;
    QString logDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation); //universally supported app's location regardless of platform
    QDir dir(logDir);
    //QMessageBox::warning(this, "Error","path: "+logDir);
    // Create directory if it doesn't exist
    if (!dir.exists() && !dir.mkpath(".")) {
        //QMessageBox::warning(this, "Error", "Failed to create directory!");
        return;
    }
    QString logPath = logDir + "/Database.txt";
    QFile file(logPath);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << username <<" "<< answer1 <<" "<< answer2 <<" "<< answer3 << "\n"; //wirte to the database
        file.close();
    } else {
        //QMessageBox::warning(this, "Error",
                             //"Could not open file: " + file.errorString());
    }
}

void MainWindow::correctAnswer(){
    curansw++;
    updateFunction();
}

void MainWindow::wrongAnswer(){
    updateFunction();
}

void MainWindow::switchToMainPage() {
    ui->stackedWidget->setCurrentIndex(0); // Switch to MainPage
}

void MainWindow::switchToRegisterPage() {
    ui->stackedWidget->setCurrentIndex(1); // Switch to RegisterPage
}

void MainWindow::switchToAboutPage(){
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::switchToHelpPage(){
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_recordButton_clicked()
{
    if (m_isRecording) {
        stopRecording();
    } else {
        startRecording();
    }
}

void MainWindow::startRecording()
{
    QString outputFile = QDir::temp().absoluteFilePath("recording.wav");
    m_mediaRecorder->setOutputLocation(QUrl::fromLocalFile(outputFile));
    m_mediaRecorder->record();
    m_isRecording = true;
    QPushButton *recordButton=testPage->findChild<QPushButton*>("recordButton");
    recordButton->setText("Остановить запись");
}

void MainWindow::stopRecording()
{
    m_mediaRecorder->stop();
    m_isRecording = false;
    QPushButton *recordButton=testPage->findChild<QPushButton*>("recordButton");
    recordButton->setText("Начать запись");

    //slight delay to remove race condition
    QTimer::singleShot(500, this, [this]() {
        uploadAudio(m_mediaRecorder->outputLocation().toLocalFile());
    });
}

void MainWindow::uploadAudio(const QString &filePath)
{
    QFileInfo fileInfo(filePath);
    if(!fileInfo.exists()) {
        QMessageBox::critical(this, "Error",
                              QString("File not found at: %1").arg(filePath));
        return;
    }

    QFile audioFile(filePath);
    if (!audioFile.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Error",
                              QString("Could not open audio file: %1\nError: %2")
                                  .arg(filePath)
                                  .arg(audioFile.errorString()));
        return;
    }

    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    //send audio as part of a multi-part network request
    QHttpPart audioPart;
    audioPart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("audio/wav"));
    audioPart.setHeader(QNetworkRequest::ContentDispositionHeader,
                        QVariant("form-data; name=\"file\"; filename=\"recording.wav\""));
    audioPart.setBody(audioFile.readAll());
    multiPart->append(audioPart);

    //specify the language for faster processing
    QHttpPart languagePart;
    languagePart.setHeader(QNetworkRequest::ContentDispositionHeader,
                           QVariant("form-data; name=\"language\""));
    languagePart.setBody("ru");
    multiPart->append(languagePart);
    //OpenAI-compatible api structure
    QNetworkRequest request(QUrl("http://localhost:8000/v1/audio/transcriptions?model=Systran/faster-distil-whisper-large-v3"));    //couldn't specify the bigger model as part of a multipart request, but this also works
    request.setRawHeader("Authorization", "Bearer 123");    //api "key"

    QNetworkReply *reply = m_networkManager->post(request, multiPart);
    multiPart->setParent(reply);

    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        handleApiResponse(reply);
    });
}

void MainWindow::handleApiResponse(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        QMessageBox::critical(this, "API Error", reply->errorString());
        return;
    }

    QJsonDocument response = QJsonDocument::fromJson(reply->readAll());
    QJsonObject json = response.object();
    QLabel *testText = testPage->findChild<QLabel*>("labelZadanie");
    QString string2 = testText->text();
    QMessageBox::warning(this, "label is: ", string2);

    if (json.contains("text")) {
        if (json["text"].toString().toUpper()==string2){    //if returning text matches the (uppercase) test text
            curansw++;                                      //same logic as the correctAnswer button
            updateFunction();
        }
        else{
            updateFunction();                               //...and the wrongAnswer button
        }
    } else {
        QMessageBox::warning(this, "API Error", "Unexpected response format");
    }

    reply->deleteLater();
}
