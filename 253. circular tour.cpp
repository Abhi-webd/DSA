int tour(petrolPump a[],int n)
    {
       //Your code here
        int prevp=0,currp=0,start=0;
      for(int i=0;i<n;i++)
      {
          currp+=a[i].petrol-a[i].distance;
          if(currp<0)
          {
              start=i+1;
              prevp+=currp;
              currp=0;
          }
      }
      return ((currp+prevp>=0)?(start):-1);
   }
