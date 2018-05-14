import serial
import matplotlib.pyplot as plt

def main():
    # open cmd mode to find out the port name
    ser = serial.Serial('COM4', 9600)

    # write letter 'r' to PIC in order to recieve the data
    ser.write('r')

    # each data list
    num = []
    raw = []
    MAF = []
    IIR = []
    FIR = []


    for i in range(100):
        line = ser.readline()
        print(line)
        data = line.split(', ')

        # separate the data point
        raw.append(data[1])
        MAF.append(data[2])
        IIR.append(data[3])
        FIR.append(data[4])

    # change data type from string to float number (python 2.7, for python 3 use eg. raw = list(map(float, raw))
    # print(raw)
    raw = map(float, raw)
    print(raw)
    # print(MAF)
    MAF = map(float, MAF)
    print(MAF)
    # print(IIR)
    IIR = map(float, IIR)
    print(IIR)
    # print(FIR)
    FIR = map(float, FIR)
    print(FIR)

    # plot the data
    plt.plot(raw, label='raw')
    plt.plot(MAF, label='MAF')
    plt.plot(IIR, label='IIR')
    plt.plot(FIR, label='FIR')
    plt.legend()
    plt.show()



if __name__ == '__main__': main()
