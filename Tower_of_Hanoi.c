#include <graphics.h>
#include <math.h>
#include <dos.h>
#include <conio.h>

int tower[3][10];
int top[3];
int from,to,diskInAir,l,b,u;  // from to for moving

void push(int to,int diskno)
{
	// function to put disk on tower
	tower[to-1][++top[to-1]] = diskno; //to is tower no
}

int pop(int from)
{
	// function to take topmost disk on tower
	return (tower[from-1][top[from-1]--]);
}

void drawstill()
{
	int j,i,disk;
	cleardevice();
	for(j=1;j<=3;j++)
	{	
		// for creating tower
		setfillstyle(CLOSE_DOT_FILL,WHITE);
		bar(j*l,u,j*l+5,b);
		
		for(i=0;i<=top[j-1];i++)
		{
			// for drawing disk on tower
			disk = tower[j-1][i];
			setfillstyle(SOLID_FILL,1+disk);
			bar(j*l-15-disk*5,b-(i+1)*10,j*l+5+15+disk*5,b-i*10);
		}
	}
}

void animator()
{
	// function to show movement of disk
	int x,y,dif,sign;
	diskInAir = pop(from);
	x = from*l;
	y = b-(top[from -1]+1)*10;

	for(;y>u-20;y-=15)
	{
		// taking disk upward from the tower
		drawstill();
		setfillstyle(SOLID_FILL,1+diskInAir);
		bar(x-15-diskInAir*5,y-10,x+5+15+diskInAir*5,y);
		delay(100);
	}
 	
	y =u-20;
	dif = to*l-x;
	sign = dif / abs(dif);

	// for moving disk towards target tower

	for(;abs(x-to*l)>25;x+= sign*15)
	{
		drawstill();
		setfillstyle(SOLID_FILL,1+diskInAir);
		bar(x-15-diskInAir*5,y-10,x+5+15+diskInAir*5,y);
		delay(100);
	}
	x =to*l;

	// for placing disk on target tower
	for(;y<b-(top[to-1]+1)*10;y+=15)
	{

		drawstill();
		setfillstyle(SOLID_FILL,1+diskInAir);
		bar(x-15-diskInAir*5,y-10,x+5+15+diskInAir*5,y);
		delay(100);
	}
	
	push(to,diskInAir);
	drawstill();
}

void moveTopN(int n,int a,int b,int c)
{
	// for moving top n disk from tower a to tower b
	// tower b is used for swapping disk
	if(n>=1)
	{
		moveTopN(n-1,a,c,b);
		drawstill();
		delay(1000);
		from = a;
		to = c;

		// animating the move of disk

	   	animator();
		moveTopN(n-1,b,a,c);
	}
}

void main()
{
	int i,gd = DETECT,gm,n;
	clrscr();

	printf("Enter the no of disk : ");
	scanf("%d",&n);
	
	initgraph(&gd,&gm,"C://TURBOC3//BGI");
	// setting all tower empty
	for(i=0;i<3;i++)
	{
		top[i] =-1;
	}
	
	// putting all disk on tower a 
	
	for(i=n;i>0;i--)
	{
		push(1,i);
	}
	l = getmaxx()/4;
	b = getmaxy() - 50;
	u = getmaxy()/3+100;

	moveTopN(n,1,2,3);
	delay(4000);
	getch();
	closegraph();
}		