//Jorge Sanchez Lopez
//Ejercicio 1
//Programacion II Ordinaria

#include <iostream>
#include <vector>

using namespace std;

struct Turno{
private:
    int codigo;
    int orden;
public:
    Turno(): codigo(0), orden(0){}

    Turno(int c, int o){
        if( c < 0){
            throw string ("Error, el codigo no es correcto.");
        }else{
            codigo = c;
        }
        if(o < 0 and o > 99){
            throw 1;
        }else{
            orden = o;
        }

    }

    int getCodigo() const {
        return codigo;
    }

    int getOrden() const {
        return orden;
    }

    void setCodigo(int c) {
        if( c < 0){
            throw string ("Error, el codigo no es correcto.");
        }else{
            codigo = c;
        }
    }

    void setOrden(int o) {
        if(o < 0 and o > 99){
            throw 1;
        }else{
            orden = o;
        }
    }
};

struct Informe{
private:
    string descripcion;
    int paginas;
public:
    Informe(): paginas(0) {}

    Informe(const string &d, int p) : descripcion(d){
        if(p <= 0){
            throw string ("Error, el valor de las paginas no es correcto. ");
        }else{
            paginas = p;
        }
    }

    const string &getDescripcion() const {
        return descripcion;
    }

    void setDescripcion(const string &d) {
        descripcion = d;
    }

    int getPaginas() const {
        return paginas;
    }

    void setPaginas(int p) {
        if(p <= 0){
            throw string ("Error, el valor de las paginas no es correcto. ");
        }else{
            paginas = p;
        }
    }
};

template<typename T>
class Registro{
private:
    T valor;
public:
    Registro() {}
    Registro(const T& v) : valor(v) {}

    T getValor() const {
        return valor;
    }

    void setValor(T v) {
        valor = v;
    }
    /*
    template<typename T>
    T operator++(T miTipo){
            miTipo++;
        return miTipo;
    }*/

    friend ostream &operator<<(ostream &os, const Registro &registro) {
        os << "valor: " << registro.valor;
        return os;
    }

    friend ostream &operator<<(ostream &os, const Registro &registro) {
        Turno t;
        os << "Codigo: " << t.getCodigo() << " y el orden es: " << t.getOrden();
        return os;
    }

    friend ostream &operator<<(ostream &os, const Registro &registro) {
        vector<Informe> miVector;
        for(int i = 0; i < miVector.size(); i++){
            os << "Descripcion: " << miVector.at(i).getDescripcion() << " y las paginas son: " << miVector.at(i).getPaginas();
        }
        return os;
    }
};

template<typename T>
T operator++(T miTipo){
    miTipo++;
    return miTipo;
}
/*
template<>
T operator++(T miTurno){
    int aux;
    aux = miTurno.getOrden() + 1;
    miTurno.setOrden(aux);
}*/

int main() {
    int pruebaInt;
    Turno pruebaTurno;
    vector<Informe> pruebaInforme;

    try{

    }catch (int ){
        cout << "Error, el orden no es correcto.";
    }catch(...){
        cout << "Un error cualquiera. " << endl; //Para asegurar si se me pasa una excepcion
    }

    cout << "EL programa ha terminado" << endl;

    return 0;
}
