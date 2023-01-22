#include "as5047p.h"
#include "SPI.h"

AS5047P_Instance encInstanceA;
AS5047P_Result encPositionA;

void setup() {
  pinMode(10, OUTPUT);  
  SPI.begin();
  
  AS5047P_Init(&encInstanceA, 1); // 1 requires cs = 10

  AS5047P_SetFactorySettings(&encInstanceA);

  AS5047P_SetZeroPosition(&encInstanceA);  

  AS5047P_SetFieldInRegister(&encInstanceA, AS5047P_SETTINGS1, AS5047P_SETTINGS1_PWMON, 1);

  AS5047P_SetFieldInRegister(&encInstanceA, AS5047P_SETTINGS1, AS5047P_SETTINGS1_UVW_ABI, 1);

  AS5047P_SetFieldInRegister(&encInstanceA, AS5047P_SETTINGS2, AS5047P_SETTINGS2_UVWPP, 6);
}

int isKthBitSet(int n, int k) {
    if (n & (1 << k))
      return 1;
    else
      return 0;
}

void loop2() {

}

void loop() {

  encPositionA = AS5047P_ReadPosition(&encInstanceA, AS5047P_OPT_ENABLED);

  if( !AS5047P_ErrorPending(&encInstanceA) )
  {
    //--- the block reports if chip is connected, and settings are right for burn
    Serial.print("Encoder ID[");
    Serial.print( AS5047P_GetID(&encInstanceA) );
    Serial.print("]> Position: ");
    Serial.println( (uint16_t)encPositionA );
    Serial.print("]> PWMON: ");
    Serial.println( isKthBitSet(AS5047P_ReadRegister(&encInstanceA, AS5047P_SETTINGS1, AS5047P_OPT_ENABLED), 7) );
    Serial.print("]> UVW_ABI: ");
    Serial.println( isKthBitSet(AS5047P_ReadRegister(&encInstanceA, AS5047P_SETTINGS1, AS5047P_OPT_ENABLED), 3) );

    int val = AS5047P_ReadRegister(&encInstanceA, AS5047P_SETTINGS2, AS5047P_OPT_ENABLED);
    val <<= 5;
    val >>= 5;
    Serial.print("]> PP: ");
    Serial.println( val );


  }
  else
  {
    //--- Some thing is wrong -- print error messages
    Serial.print("Encoder ID[");
    Serial.print( AS5047P_GetID(&encInstanceA) );
    Serial.print("]> Error ");
    Serial.print( AS5047P_GetError(&encInstanceA).errorCode );
    Serial.print(" : ");
    Serial.println(AS5047P_GetError(&encInstanceA).msg);

    AS5047P_ErrorAck(&encInstanceA);
  }

  // user can initiate burn by sending single characters over serial. 
  if (Serial.available() > 0) {
    int ByteReceived = Serial.read();
    
    // If user sends "x" over serial, initiate burn
    if (ByteReceived == 120) { 
      int result = AS5047P_BurnOTP(&encInstanceA, 666);
      Serial.println("]>BURN!");
      if (result == 0) {
	Serial.println(" no errors received, test if burn complete");
      }
      else {
	Serial.print(" something failed:"); Serial.println(result);
      }

      while(1){}
    }
    else if (ByteReceived == 13) {
      // end of line, ignore
    }
    else { // user sent something else
      Serial.print("type X to burn");
      delay(1000);
    }
  
  }

  delay(800);    
}
