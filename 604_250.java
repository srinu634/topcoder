 public class FoxAndWord {

    public int howManyPairs(String[] words){
        int len,count;
        len = words.length;
        int i,j,k;

        count = 0;

        for(i=0;i<len;i++)   // nc2
            for(j=i+1;j<len;j++)
                {
                    if( words[i].length() != words[j].length())
                        continue; // Can't Form a pair : Base Case
                    int strlen = words[i].length();
                    for(k=0;k<strlen;k++)
                        {
                            String temp;
                            temp = words[j].substring(k,strlen)+words[j].substring(0,k); //Rotating it
                            //System.out.println(temp+" "+words[i] + " " + words[j]);
                            if( words[i].equals(temp) == true ){
                                count++;
                                break;
                            }
                        }
                }
return count;
    } // method


    public static void main(String args[])
    {
   FoxAndWord f = new FoxAndWord();
    String arr[] = {"ababab","b","c","ad","da"};
    System.out.println( f.howManyPairs( arr) );
    }

} //class
