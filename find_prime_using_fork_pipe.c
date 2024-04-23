#include<stdio.h>
#include<unistd.h>
#include<stdbool.h> //need to use this when we include boolean below


int main()
{
    int arr[2];
    

    if(pipe(arr)==-1)
    {
        printf("Failed to create pipe.. ");
    }


    
    int id=fork();

    if(id==0)
    {
        //child process


        //get input
        int a;  /*this 'a' is a local variable to if condition.we need to pass the 
         value we get to this variable to the parent process.thats why we need pipe*/

        printf("Enter a number to find whether prime or not : ");
        scanf("%d",a);

        //send value to parent..write the value

        close(arr[0]); //we need to close read end(arr[0]) of the pipe array(arr) before write(1) 
        write(arr[1],&a,sizeof(a)); //write the value..write end is 1
        close(arr[1]); //close the write end(arr[1])
    }

    else{
        //parent process

        wait(NULL);

        //read the value which come from child process

        int b;

        close(arr[1]); //we need to close write end (arr[1]) before read
        read(arr[0],&b,sizeof(b)); //read value coming from the child process
        close(arr[0]); //close the read end(arr[0])

        
      
          bool isprime=false;
          int i;

          for(i=2;i<b;i++)
          {
             if(b%i==0)
             {
                  printf("Not a prime number..");
                  isprime=true;
                  break;
             }

          }

         if(isprime==false)
         {
             printf("Prime number..");
         }
      }

     
    return 0;
}


    


    
    



   

    
    


    