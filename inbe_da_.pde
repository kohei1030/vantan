void setup(){
  size(500,500);
}

int x=0,y=0;
int count;
boolean flag_x = false;
boolean flag_c = false;

void draw(){
  
  background(100,100,100);
  
  
  
///////////////////////////////////////  
  count++;
  if(count%30==0)flag_c = !flag_c;
  
  for(int i = 0;i<10;i++){
    if(flag_c)fill(0);
    else fill(200,200,200);
  rect(41*i+x,y,40,40);
  }
  
  if(flag_x)x++;
  else x--;
  
  if((x+41*9+40)>500||x<0){
    flag_x = !flag_x;
    y+=50;
  }
  if(y+40>500){
    y = 0;
  }
///////////////////////////////////////
}
