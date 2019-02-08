#pragma once

#include <OpenGL/OpenGLWindow.h>
#include <UI/SceneTreeWidget.h>

class MainWindow: public QMainWindow {
    Q_OBJECT

public:
    MainWindow(Scene * scene, QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Scene *m_host;
    AbstractEntity* m_copyedObject;

    QSplitter * m_splitter;
    QLabel* m_fpsLabel;

    SceneTreeWidget *m_sceneTreeWidget;
    OpenGLWindow *m_openGLWindow;
    QWidget *m_propertyWidget;

    void configMenu();
    void configLayout();
    void configSignals();

private slots:
    void fpsChanged(int fps);
    void itemSelected(QVariant item);
    void itemDeselected(QVariant item);

    void fileNewScene();
    void fileOpenScene();
    void fileImportModel();
    void fileExportModel();
    void fileSaveScene();
    void fileSaveAsScene();
    void fileQuit();

    void editCopy();
    void editPaste();
    void editRemove();

    void createGridline();
    void createAmbientLight();
    void createDirectionalLight();
    void createPointLight();
    void createSpotLight();
    void createBasicCone();
    void createBasicCube();
    void createBasicCylinder();
    void createBasicPlane();
    void createBasicSphere();

    void setAxisTypeTranslate();
    void setAxisTypeRotate();
    void setAxisTypeScale();
    
    void helpAbout();
    void helpSourceCode();
    void helpCheckForUpdates();
    void replyOfUpdates(QNetworkReply* reply);
};
