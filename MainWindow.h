#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMessageBox>
#include <QMainWindow>
#include <QStackedWidget>
#include <QTextEdit>
#include <QListWidget>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>

#include <QMediaCaptureSession>
#include <QAudioInput>
#include <QMediaRecorder>
#include <QNetworkAccessManager>

// Forward declarations for UI classes
namespace Ui {
class MainWindow;
class LoginPage;
class MainPage;
class DatabasePage;
class HelpPage;
class AboutPage;
class TestPage;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void switchToMainPage();
    void switchToRegisterPage();
    void switchToAboutPage();
    void switchToTestPage();
    void switchToHelpPage();
    void switchToDatabasePage();

    void registerUser();
    void correctAnswer();
    void wrongAnswer();
    void updateFunction();
    void writeResults();

    void on_recordButton_clicked();
    void handleApiResponse(QNetworkReply *reply);


private:
    Ui::MainWindow *ui;
    QWidget *loginPage;
    QWidget *mainPage;
    QWidget *aboutPage;
    QWidget *helpPage;
    QWidget *databasePage;
    QWidget *testPage;

    QMediaCaptureSession m_captureSession;
    QAudioInput *m_audioInput = nullptr;
    QMediaRecorder *m_mediaRecorder = nullptr;
    QNetworkAccessManager *m_networkManager = nullptr;
    bool m_isRecording = false;

    void startRecording();
    void stopRecording();
    void uploadAudio(const QString &filePath);
};

#endif // MAINWINDOW_H
