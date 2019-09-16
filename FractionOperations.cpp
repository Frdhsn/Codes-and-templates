class fraction{
public:
    ll nom,denom;
    fraction(){
        nom = denom = 0;
    }
    fraction(ll x){
        nom = x , denom= 1;
    }
    fraction(ll x,ll y){
        nom = x , denom= y;
    }
    void norm(){
        ll g = __gcd(nom,denom);
        nom/=g;
        denom/=g;
        if(nom==0)denom=1;
        if(denom<0)denom*=-1,nom*=-1;
    }
    fraction operator + (fraction obj){

        ll lc = lcm(obj.denom,denom);
        fraction r ( nom*(lc/denom) + obj.nom*(lc/obj.denom), lc );
        r.norm();
        return r;
    }
    fraction operator - (fraction obj){
        ll lc = lcm(obj.denom,denom);
        fraction r ( nom*(lc/denom) - obj.nom*(lc/obj.denom), lc );
        r.norm();
        return r;
    }

    fraction operator * (ll x){
        return {nom*x , denom};
    }
    void print(){
        cerr<<nom<<"/"<<denom<<endl;
    }
};
