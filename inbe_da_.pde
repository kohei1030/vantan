void setup(){
  size(500,500);  
}

float x=0,y=5;
int count = 0;
boolean flag_x = false;
boolean flag_c = false;

void draw(){
  
  background(100,100,100);

  PImage enemy;
  PImage enemy2;

  enemy = loadImage("enemy.png");
  enemy2 = loadImage("enemy2.png");
///////////////////////////////////////  
  count++;
  if(count%30==0)flag_c = !flag_c;
  
  for(int i = 0;i<10;i++){
    if(flag_c)  image(enemy,41*i+x,y,40,40);
    else   image(enemy2,41*i+x,y,40,40);
  }
  
  if(flag_x)x+=1.5;
  else x-=1.5;
  
  if((x+41*9+40)>500||x<0){
    flag_x = !flag_x;
    y+=50;
  }
  if(y+40>500){
    y = 5;
  }
///////////////////////////////////////
}
