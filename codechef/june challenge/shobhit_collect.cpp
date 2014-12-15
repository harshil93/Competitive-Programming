#include "iostream"
#include "cstdio"
#include "vector"
#include "string"
#include "cmath"

#ifndef MOD
#define MOD 3046201
#endif
typedef long long int lld;

using namespace std;
lld modFactorial[3000002];
// std::vector<lld> modInvFact;
lld input[100001];


inline lld fastRead(lld n)
{
	for (int i = 0; i < n; ++i)
	{
		register char c=0;
		while(c<33)
			c=getchar_unlocked();
		lld temp=0;
		while(c>33)
		{
			temp=temp*10+c-'0';
			c=getchar_unlocked();
		}
		input[i]=temp;
	}
}

inline lld fastReadNo()
{
	register char c=0;
	while(c<33)
		c=getchar_unlocked();
	lld temp=0;
	while(c>33)
	{
		temp=temp*10+c-'0';
		c=getchar_unlocked();
	}
	return temp;
}

void calcFactorial()
{
	for (lld i = 1; i <= 3000000; ++i)
	{
		lld temp=modFactorial[i-1]*i;
		if (temp>=MOD)
		{
			modFactorial[i]=temp%MOD;
		}
		else
			modFactorial[i]=temp;
	}
}

/*void storeInvFact(int reqIndex)
{
	lld n =modInvFact.size()-1;
	for (lld i = n; i !=reqIndex-1; --i)
	{
		lld temp=modInvFact.back()*i;
		if (temp>=MOD)
		{
			modInvFact.push_back(temp%MOD);
		}
		else
			modInvFact.push_back(temp);
	}
}*/

lld fact(lld n)
{
	// cout<<modFactorial[n]<<endl	;
	return modFactorial[n];
}

lld powMod(lld a,lld power)
{
	if (a==1)
	{
		return 1;
	}
	
	std::vector<lld> powerDP;
	lld count=0;
	lld answer=1;
	powerDP.push_back(a);
	lld powerTemp=power>>1;
	while(powerTemp!=0)
	{
		lld temp=powerDP.back()*powerDP.back();
		temp=(temp>=MOD)?temp%MOD:temp;
		powerDP.push_back(temp);
		powerTemp=powerTemp>>1;
		// cout<<powerTemp<<endl;

	}
		// cout<<powerDP.size();

	while(power!=0)
	{
		if (power & 1)
		{
			answer=answer* powerDP[count];
			answer=(answer>=MOD)?answer%MOD:answer;
			
		}
		power=power>>1;
		count++;
	}
	
	return answer;
	
}

/*lld calcinvfact(lld n)
{
	return powMod(modFactorial[n],MOD-2);
	// cout<<answer<<"\t";
}*/

lld invfact(lld n)
{
	return powMod(modFactorial[n],MOD-2);
	/*cout<<3000000-n<<" "<<modFactorial.size()<<endl;
	if (3000000-n<modInvFact.size())
	{
		return modInvFact[3000000-n];
	}
	else
	{
		cout<<"before"<<" "<<modFactorial.size()<<endl;
		storeInvFact(3000000-n);
		cout<<"after"<<" "<<modFactorial.size()<<endl;
		return modInvFact[3000000-n];
	}*/
	
}
lld getMid(lld s, lld e) {  return s + (e -s)/2;  }

lld getSumUtil(lld *st, lld ss, lld se, lld qs, lld qe, lld index)
{
    // If segment of this node is a part of given range, then return the
    // sum of the segment
    if (qs <= ss && qe >= se)
        return st[index];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return 0;
 
    // If a part of this segment overlaps with the given range
    lld mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*index+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*index+2);
}

void updateValueUtil(lld *st, lld ss, lld se, lld i, lld diff, lld index)
{
    // Base Case: If the input index lies outside the range of this segment
    if (i < ss || i > se)
        return;
 
    // If the input index is in range of this node, then update the value
    // of the node and its children
    st[index] = st[index] + diff;
    if (se != ss)
    {
        lld mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*index + 2);
    }
}

void updateValue(lld arr[], lld *st, lld n, lld i, lld new_val)
{
    // Check for erroneous input index
    if (i < 0 || i > n-1)
    {
        printf("Invalid Input");
        return;
    }
 
    // Get the difference between new value and old value
    lld diff = new_val - arr[i];
 
    // Update the value in array
    arr[i] = new_val;
 
    // Update the values of nodes in segment tree
    updateValueUtil(st, 0, n-1, i, diff, 0);
}

lld getSum(lld *st, lld n, lld qs, lld qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}

lld constructSTUtil(lld arr[], lld ss, lld se, lld *st, lld si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    lld mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}

lld *constructST(lld arr[], lld n)
{
    // Allocate memory for segment tree
    lld x = (lld)(ceil(log2(n))); //Height of segment tree
    lld max_size = 2*(lld)pow(2, x) - 1; //Maximum size of segment tree
    lld *st = new lld[max_size];
 
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);
 
    // Return the constructed segment tree
    return st;
}

int main(int argc, char const *argv[])
{
	lld n,q,index,newValue,l,r,people,berries,answer;
	// lld *input;
	scanf("%lld",&n);
	// input=new lld[n];
	fastRead(n);
	

	lld *st = constructST(input, n);
	scanf("%lld",&q);
	char c;
	while((c=getchar_unlocked())=='\n');

	modFactorial[0]=1;
	calcFactorial();
	// modInvFact.push_back(calcinvfact(3000000));
	// storeInvFact();
	
	while(q>0)
	{
		string text;
		answer=1;
		do
		{
			text.push_back(c);
		}while((c=getchar_unlocked())!=' ');
		if (text[0]=='c')
		{
			// scanf("%lld%lld",&index,&newValue);
			index=fastReadNo();
			newValue=fastReadNo();
			updateValue(input, st, n, index-1, newValue);
		}
		else
		{
			// scanf("%lld%lld",&l,&r);
			l=fastReadNo();
			r=fastReadNo();
			people=r-l+1;
			berries=getSum(st, n, l-1, r-1);
			
			lld least=berries/people;
			lld peopleGettingMore=berries%people;

			// cout<<least<<" "<<peopleGettingMore<<endl;

			lld temp=powMod(invfact(least+1),people);
			temp=temp*fact(berries);
			temp=(temp>=MOD)?temp%MOD:temp;

			lld peopleLeft=people- peopleGettingMore;
			temp=temp*powMod(least+1,peopleLeft);
			temp=(temp>=MOD)?temp%MOD:temp;
			answer=temp;

			lld temp2=fact(people)*invfact(peopleGettingMore);
			temp2=(temp2>=MOD)?temp2%MOD:temp2;
			temp2=temp2*invfact(people- peopleGettingMore);
			temp2=(temp2>=MOD)?temp2%MOD:temp2;
			// cout<<temp2<<endl;
			temp2=answer*temp2;
			answer=(temp2>=MOD)?temp2%MOD:temp2;

			printf("%lld\n", answer);
		}
		q--;
	}

	return 0;
}