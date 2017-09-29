/**
 *  Robô Autonômo - Rôbo que desvia de obstáculo sozinho
 *  @author : Walderlan Sena <contato@mentesvirtuaissena.com>
 *  @version: v1.0.0
 *  @site   : https://www.github.com/WalderlanSena
 */
#include <Ultrasonic.h>
#include <AFMotor.h>

//---------- Constantes do software ----------
#define TRIG 19
#define ECHO 15
#define MOTOR01 1
#define MOTOR02 4

//---------- Configurações Iniciais ----------

Ultrasonic ultrasonic(TRIG, ECHO);    //Criando um objeto do tipo Ultrasonic e passando para 

AF_DCMotor motor1(MOTOR01);           //Define o motor1 ligado a conexao 2
AF_DCMotor motor2(MOTOR02);           // Define o motor2 ligado a conexao 3

//---------- Protótipos das funções ----------
void verifyDistance(void);
void stopRobot(void);
void startRobot(void);
void back(void);
void turnRight();
void turnLeft(void);

//========== Setup ==========
void setup () 
{
  Serial.begin(9600);                 //Setando a frequência do serial begin
}//end setup

//========== Loop Infinito ==========
void loop () 
{
  verifyDistance();
  
}//end loop
//---------- Implementação das funções ----------
void verifyDistance ()
{
  float distance = ultrasonic.distanceRead(); //Capturando a distância obtida pelo sensor ultrasonico
  delay(1000);
  Serial.print("A distâcia é: ");
  Serial.println(distance);
  if (distance < 100) {                       //Verifica se o distância é menor ou igual a 20CM
    stopRobot();                              //Se sim para o rôbor e muda a direção
  } else {                                    //Caso não
    startRobot();                             //Rôbo continua em frente
  }//end if  
}//end verifyDistance

void startRobot() 
{
  motor1.setSpeed(255);                       //Setando a velociadade do motor1
  motor2.setSpeed(255);                       //Setando a velociadade do motor2
  
  motor1.run(BACKWARD);                       //Aciona o motor 1 no sentido horario
  motor2.run(BACKWARD);                       //Aciona o motor 2 no sentido horario
}//end startRobot


void stopRobot()
{
  motor1.run(RELEASE);                      //Pausando o motor1
  motor2.run(RELEASE);                      //Pausando o motor2
}//end stopRobot

/**
 *  Ré para verificar distancia novamente
 */
void back()
{
  motor1.setSpeed(150);                      //Setando a velociadade do motor1
  motor2.setSpeed(150);                      //Setando a velociadade do motor2
  
  motor1.run(FORWARD);
  motor2.run(FORWARD);                       //Aciona o motor 2 no sentido horario

  verifyDistance();
}//end re 


/**
 *  Vira o rôbo para a direita
 */
void turnRight()
{  
  motor1.setSpeed(100);                     //Setando a velociadade do motor1
  motor2.setSpeed(90);                      //Setando a velociadade do motor2
  
  motor1.run(BACKWARD);                     //Aciona o motor 1 no sentido horario
  motor2.run(FORWARD);                      //Aciona o motor 2 no sentido anti-horario
}//end Right

/**
 *  Vira o rôbo para a esquerda
 */
void turnLeft()
{
  motor1.setSpeed(100);                     //Setando a velociadade do motor1
  motor2.setSpeed(90);                      //Setando a velociadade do motor2
  
  motor1.run(FORWARD);                      //Aciona o motor 1 no sentido anti-horario
  motor2.run(BACKWARD);                     //Aciona o motor 2 no sentido horario
}//end turnLeft
