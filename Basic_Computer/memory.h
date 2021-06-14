#ifndef MEMORY_BUVBBCHJEWBCHNCUBEUI
#define MEMORY_BUVBBCHJEWBCHNCUBEUI

#include <QObject>

class Memory : public QObject
{
    Q_OBJECT
private:
    long long int array[1024];
public:
    explicit Memory(QObject *parent = nullptr);
    void write(int address, long long int value);
    long long int read(int address);
signals:

};

#endif // MEMORY_H
