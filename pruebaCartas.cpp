#include"carta.h"
#include"cola.h"
#include<algorithm>

bool solitario(cola<tcarta>&mazO);
int main(){
	std::srand(time(NULL));
	tcarta baraja[40];
	bool victoria = false;
	int partidas=0;
	cola<tcarta> mazo;
	for(int i=0,p=oro;p<=copas;p++){
		for(int f=as;f<=rey;f++,i++){
			baraja[i]= tcarta(Cpalo(p),Cfig(f));
		}
	}
	
	while(!victoria){
		std::random_shuffle(baraja,baraja+40);
		for(int i=0;i<40;i++){
			mazo.push(baraja[i]);
		}
		victoria=solitario(mazo);
		partidas++;
		if(!mazo.vacia()){
			mazo.~cola();
		}
		std::cout<<"a";
	}
	std::cout<<"Has ganado y solo te han hecho falta "<<partidas<<" puto inutil";
	return 0;
}

bool solitario(cola<tcarta>&mazO){
	bool vic;
	int contador=0;
	Cfig ulti =Cfig(rand()%10);
	std::cout <<"Emepezamos con "<<ulti+1<<std::endl;
	Cfig sig;
	cola <tcarta> m;
	cola<tcarta> montones[10];
	int puestas[]={0,0,0,0,0,0,0,0,0,0};
	for(int i=0; i<10;i++){
		montones[i]=m;
		std::cout<<"Monton "<<i+1<<":";
		for(int j=0;j<4;j++){
			montones[i].push(mazO.frente());
			std::cout<<mazO.frente().figura();
			mazO.pop();
		}
		std::cout<<std::endl;
	}
	while(contador!=4&&puestas[9]!=4){
		sig=montones[ulti].frente().figura();
		if(sig==ulti){
			contador++;
			puestas[ulti]++;
			std::cout <<"se ha puesto una repe en "<<ulti<<std::endl;
			montones[ulti].push(montones[ulti].frente());
			montones[ulti].pop();
		}
		else{
			contador=0;
			montones[sig].push(montones[ulti].frente());
			std::cout <<"se ha puesto una NO repe en "<<sig<<std::endl;
			montones[ulti].pop();
			puestas[sig]++;
			ulti=sig;
		}
	}
	if(puestas[9]==4){
		vic=true;
	}
	else{
		vic=false;
	}
	for(int i=0; i<10; i++){
		std::cout<<puestas[i]<<std::endl;
	}
	return vic;
}




