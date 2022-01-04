#ifndef __CARTA__
#define __CARTA__
#include<ostream>
enum Cfig {as,dos,tres,cuatro,cinco,seis,siete,sota,caballo,rey};
enum Cpalo{oro,espada,bastos,copas};
class tcarta{
	public:
		tcarta(Cpalo p=oro,Cfig f=as):palo_(p),fig_(f){};
		Cpalo palo()const{return palo_;};
		Cfig figura()const{return fig_;};
	//	friend std::ostream& operator<<(std::ostream&os,const tcarta&c);
	private:
		Cpalo palo_;
		Cfig fig_;
//		static const char* nom_palo[],*nom_fig[];
};
#endif


