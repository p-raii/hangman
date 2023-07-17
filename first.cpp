#include <iostream>
#include <string>
#include<cstring>
using namespace std;
    #define a " _____"
    #define b "|   _|_"
    #define c "|  [*_*]"
    #define d "|  / | \\"
    #define e "|   ! !"
    #define f "|"
 // class to perform main action for the game   
class action{
public:
	string ch,w;
	int len,attempt=0,g;

	//to choose a word from options
	int choose()
	{
    int choice;
	game:
	cout<<"Choose a number between 0-4 for the word \n";
	cin>>choice;
	if (choice>4 || choice<0)
	{
	cout<<"------ERROR------\nEnter valid choice \n \n";
	goto game;
	}
	else{
	w=word(choice);
	}
	set(w);
	return len;
}

    // to display progress in hangman
	void result(int attempt)
	{
    switch(attempt){
    	case 1:
    		cout<<a<<endl<<b<<endl<<f<<endl<<f<<endl<<f<<endl<<f<<endl ;
    		break;
    	case 2:
    		cout<<a<<endl<<b<<endl<<c<<endl<<f<<endl<<f<<endl<<f<<endl ;
    		break;
    	case 3:
    		cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<f<<endl<<f<<endl ;
    		break;
    	case 4:
    	    cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f<<endl ;	
    		break;
    	default:
		break;	
			}
}

    // to initially set the value
	void set(string& w)
	{
    len= w.length();
    if (len<=3){
     	ch.replace(1,len-1,len-1,'_');
     	g=1;
     	return;
	}
	for(int i=0; i<len;i++){
	if(!(i==0|| i==len/2)){
	ch.replace(i,1,"_");
	}
    }
    g=2;
	}
	
	//to display the progress
	void display()
	{
	cout<<endl;
	for(int i=0;i<len;i++){
		cout<<ch[i]<<" ";
	}
	cout<<endl;
	}
	
	//to change the initial set word according to guess 
	int change(char guess)
	{
    int dummy=1;
	for(int i=0;i<len;i++){
	if(guess==w[i] && ch[i]!=guess) {
		ch[i]=guess;
		dummy=0;
		g++;
	}
    }   
	if(dummy==1){
	attempt++;
	}
	display();
	result(attempt);
	if(attempt==4){
	return -1;
	}
	if(g==len){
	return 1;
	}
	return 0;	
	}
	
	//the given choice of words
	string word(int choice)
	{
	string w[]={"apple","ball","box","beautiful","haha"};
	ch=w[choice];
	return ch;
	} 
	};


int main(){
    cout<<"--------HANGMAN---------\nYou have to guess the given word.\nYou have four strikes.\n------Best of luck-------\n \n";
	action p1; //creating object of class action
	p1.choose();
	p1.display();
	while(1){	
	char guess;
	cout<<"\nEnter your guess\n";
	cin>>guess;
	int final =p1.change(guess);
	if(final==-1){
	cout<<"----GAME OVER---- \n     YOU LOSE:'(";
	break;
	}
	else if (final==1){
	cout<<"----YOU WIN---- :)";
	break;
	}
	else{
	continue;
	}
	}
}


