#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QImage>
int main(int argc, char* argv[])
{
    qDebug() << "  eg:" << "pic2ico a.png b.ico 128\n";
    QDir dir;
    QString fileName = argv[1];
    QString retName = argv[2];
    if (retName == "")
    {
        retName = "ret.ico";
    }
    QString retSize = argv[3];
    bool ok;
    int isize = retSize.toInt(&ok);
    if (!ok)
    {
        isize = 128;
    }
    QString filePath = dir.currentPath() + "/" + fileName;
    QImage img(filePath);
    img = img.scaled(isize, isize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QString savePath = dir.currentPath() + "/" + retName;
    img.save(savePath, "ico");
    qDebug() << "  src:" << filePath;
    qDebug() << "  dest:" << savePath;
    return 0;
}
