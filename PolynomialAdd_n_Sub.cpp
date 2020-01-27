#include<iostream>
using namespace std;

class Polynomial
{
  private:
    int poly[20],length;
	// Variables to store information about polynomial
  public:
    Polynomial()
    {
    	poly[0]=0;
    	length=0;
      // Behavior of default constructor
    }

    Polynomial(int deg)
    {
    	length=deg;
      // Behavior of constructor with arguments
    }
  
    ~Polynomial()
    {
      // Behavior of destructor
    }
    
    Polynomial operator+(const Polynomial pol)
    {
    	Polynomial p;
    	int i,j;
    	if(length<=pol.length)
    	{
    		p.length=pol.length;
    		for(i=0;i<=length;i++)
    		p.poly[i]=poly[i]+pol.poly[i];
    		for(;i<=pol.length;i++)
    		p.poly[i]=pol.poly[i];
		}
		else
		{
			p.length=length;
    		for(j=0;j<=pol.length;j++)
    		p.poly[j]=poly[j]+pol.poly[j];
    		for(;j<=length;j++)
    		p.poly[j]=poly[j];
		}
		return p;
	}
	Polynomial operator-(const Polynomial pol)
    {
    	Polynomial p;
    	int i,j;
    	if(length<=pol.length)
    	{
    		p.length=pol.length;
    		for(i=0;i<=length;i++)
    		p.poly[i]=poly[i]-pol.poly[i];
    		for(;i<=pol.length;i++)
    		p.poly[i]=pol.poly[i];
		}
		else
		{
			p.length=length;
    		for(j=0;j<=pol.length;j++)
    		p.poly[j]=poly[j]-pol.poly[j];
    		for(;j<=length;j++)
    		p.poly[j]=poly[j];
		}
		return p;
	}
	Polynomial(const Polynomial &c)
	{
		length=c.length;
		for(int i=0;i<=length;i++)
		{
			poly[i]=c.poly[i];
		}
	}
	Polynomial operator=(const Polynomial k)
	{
		length=k.length;
		for(int i=0;i<=length;i++)
		{
			poly[i]=k.poly[i];
		}
	}
  
    //  Overload copy constructor, +, - and = operators
  
    void storePolynomial()
    {
    	for(int i=0;i<=length;i++)
    	{
    		cin>>poly[i];
		}
      //  Code to enter and store polynomial
    }
    void display()
    {
    	for(int i=0;i<=length;i++)
    	{
    		cout<<poly[i];
    		if(i!=0)
    		cout<<"x^"<<i;
    		if(i!=length)
    		cout<<"+";
		}
		cout<<endl;
      //  Code to print the polynomial in readable format
    }
  
};

int main()
{
  int degFirst, degSecond;
  cout<<"Enter degree of first polynomial ";
  cin>>degFirst;
  cout<<"Enter degree of second polynomial ";
  cin>>degSecond;
  // Ask user to input the values of degFirst and degSecond 
  Polynomial firstPolynomial(degFirst);
  Polynomial secondPolynomial(degSecond);
  Polynomial thirdPolynomial;
  
  cout<<"Enter first polynomial \n";
  firstPolynomial.storePolynomial();
  cout<<"Enter second polynomial \n";
  secondPolynomial.storePolynomial();
  
  
  thirdPolynomial=firstPolynomial+secondPolynomial;  
  Polynomial fourthPolynomial=firstPolynomial-secondPolynomial;
  
  cout<<"First polynomial..\n";
  firstPolynomial.display();
  cout<<"\nSecond polynomial..\n";
  secondPolynomial.display();
  cout<<"\nThird polynomial..addition of first two \n";
  thirdPolynomial.display();
  cout<<"\nFourth polnomial..subtraction of first two \n";
  fourthPolynomial.display();
  Polynomial fifthPolynomial=thirdPolynomial;
  cout<<"\nFifth polynomial..";
  fifthPolynomial.display();
  firstPolynomial=secondPolynomial;
  cout<<"First polynomial..after assignment operator \n";
  firstPolynomial.display();
}
