/****************************************************************************************
**  This is example LINX firmware for use with the ESP32 device
**
**  For more information see:           www.labviewmakerhub.com/linx
**  For support visit the forums at:    www.labviewmakerhub.com/forums/linx
**
**  Written By Ken Sharp
**
**  BSD2 license.
****************************************************************************************/

//Include All Peripheral Libraries Used By LINX
#include <SPI.h>
#include <Wire.h>
#include <EEPROM.h>
#include <ESP32Servo.h>
#include <WiFi.h>

//Include Device Specific Header From Sketch>>Import Library (In This Case LinxESP32.h)
//Also Include Desired LINX Listener From Sketch>>Import Library (In This Case LinxESP32WifiListener.h)
#include <LinxESP32.h>
#include <LinxESP32WifiListener.h>

//Create A Pointer To The LINX Device Object We Instantiate In Setup()
LinxESP32* LinxDevice;

//Initialize LINX Device And Listener
void setup()
{
  //Instantiate The LINX Device
  LinxDevice = new LinxESP32();

  //The LINX Listener Is Pre Instantiated.
  //Set SSID (Network Name), Security Type, Passphrase/Key, And Call Start With Desired Device IP and Port
  //If not set, it will connect with the last connection information
  //LinxWifiConnection.SetSsid("YOUR_NETWORK_NAME");
  //LinxWifiConnection.SetSecurity(WPA2_NONE);  //NONE, WPA2_PASSPHRASE, WPA2_KEY, WEP40, WEO104
  //LinxWifiConnection.SetPassphrase("PASSPHRASE");

  //Start With Fixed Port.  When Using This Method You Cannot Update The Port Using LINX VIs
  LinxWifiConnection.Start(LinxDevice, 44300);
}

void loop()
{
  //Listen For New Packets From LabVIEW
  LinxWifiConnection.CheckForCommands();

  //Your Code Here, But It will Slow Down The Connection With LabVIEW
  delay(1);
}
