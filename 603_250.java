class Test{

public static void main(String args[]) {
Test t = new Test();

System.out.println( t.encode("a") );

}





public String encode(String s){
int slen,tlen;
int i;
String t1,t2,t;
String str;
str=s;
slen = str.length();
t = new String("");//Empty string initially

if(slen==1) return str; //Base case

while(true){
        i = str.length();i--;
        if(i==1) break; //of length 2

    if(i%2==0){ //ODD LEN
        t = t + str.substring(i/2,i/2+1);
        str = str.substring(0,i/2) + str.substring(i/2+1,i+1);
    }
else{
    if( str.charAt(i/2)< str.charAt(i/2+1) )
    {
        t = t + str.substring(i/2,i/2+2);
        str = str.substring(0,i/2) + str.substring(i/2+2,i+1);
    }
    else{
        t = t + str.substring(i/2+1,i/2+2) + str.substring(i/2,i/2+1);
        str = str.substring(0,i/2) + str.substring(i/2+2,i+1);
    }
}
//System.out.println(t + " " + str);
}//while


if(str.charAt(0)<str.charAt(1))
    return t + str.substring(0,2);
else
    return t + str.substring(1,2)+str.substring(0,1);
}//encode

}//class
