#include <QCoreApplication>
#include <map>
#include <iostream>

#include "DeviceEnumerator.h"
// In Qt remember to link ole32.lib and oleaut32.lib
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    /*
        The id field of the Device struct can be used with an OpenCV VideoCapture object
    */

    DeviceEnumerator de;

    // Audio Devices
    std::map<int, Device> devices = de.getAudioDevicesMap();

    // Print information about the devices
    for (auto const &device : devices) {
        std::cout << "== AUDIO DEVICE (id:" << device.first << ") ==" << std::endl;
        std::cout << "Name: " << device.second.deviceName << std::endl;
        std::cout << "Path: " << device.second.devicePath << std::endl;
    }

    // Video Devices
    devices = de.getVideoDevicesMap();

    // Print information about the devices
    for (auto const &device : devices) {
        std::cout << "== VIDEO DEVICE (id:" << device.first << ") ==" << std::endl;
        std::cout << "Name: " << device.second.deviceName << std::endl;
        std::cout << "Path: " << device.second.devicePath << std::endl;
    }
    return a.exec();
}
