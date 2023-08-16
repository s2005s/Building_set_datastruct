#include <iostream>
#include <vector>
using namespace std;

class SET
{
public:
    vector<int> setName;
    vector<vector<int> > setValue;//important to keep gap betwee two "<"
    
    
      
    SET() 
    {
        
        
    }

    int get_index(int num,vector<int>& list,int size) 
    {
        for (int i = 0; i < size; i++) 
        {
            if (list[i] == num)
                return i;
        }
        return -1; 
    }

    
    void sort(vector<int>& vect, int size) 
    {
        bool swapped;
        for (int i = 0; i < size - 1; i++) 
        {
            swapped = false;
            for (int j = 0; j < size - i - 1; j++) 
            {
                if (vect[j] > vect[j + 1]) 
                {
                    swap(vect[j], vect[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped)
                break; 
        }
    }

    int insert(int set_num, int data) 
    {
        int index = get_index(set_num,setName,setName.size());
        if (index == -1) 
        {
            setName.push_back(set_num);
            index = setName.size() - 1;
            setValue.push_back(vector<int>());
        }
        int ind=get_index(data,setValue[index],setValue[index].size());
        if (ind==-1)
          {
            setValue[index].push_back(data);
            sort(setValue[index], setValue[index].size());
          }

        return setValue[index].size();
    }

    int Delete(int set_num,int data)
    {
      int index = get_index(set_num,setName,setName.size());
      if (index == -1)
        return -1;
      else
      {
        int ind=get_index(data,setValue[index],setValue[index].size());
        if (ind==-1)
        {
          return setValue[index].size();
        }
        else
        {
          setValue[index].erase(setValue[index].begin() + ind);
        }
      }
      return setValue[index].size();
      

    }
    int BelongsTo(int set_num,int data)
    {
      int index = get_index(set_num,setName,setName.size());
      if (index == -1)
        return -1;
      else
      {
        int ind=get_index(data,setValue[index],setValue[index].size());
        if (ind==-1)
        {
          return 0;
        }
        else
        {
          return 1;
        }
      }
    }
    int size(int set_num)
    {
      int index = get_index(set_num,setName,setName.size());
        if (index == -1) 
        {
            setName.push_back(set_num);
            index = setName.size() - 1;
            setValue.push_back(vector<int>());
            return 0;
        }
        else
        {
          return setValue[index].size();
        }
    }
    void print(int set_num)
    {
      int index = get_index(set_num,setName,setName.size());
        if (index == -1) 
        {
            cout<<"\n";
        }
        else
        {
          if(setValue[index].size()==0)
          {
            cout<<"\n";
          }
          else
          {
            for (int j = 0; j < setValue[index].size()-1; j++) 
              {
                  cout << setValue[index][j]<<",";

              }cout<<setValue[index][setValue[index].size()-1]<<"\n";
          }
        }
    }
    int Union(int set_num1,int set_num2)
    {
      int index2 = get_index(set_num2,setName,setName.size());
      int index1 = get_index(set_num1,setName,setName.size());
      if (index1==-1)
      {
            setName.push_back(set_num1);
            index1 = setName.size() - 1;
            setValue.push_back(vector<int>());
            
      }
      if (index2==-1)
      {
            setName.push_back(set_num2);
            index2 = setName.size() - 1;
            setValue.push_back(vector<int>());
            
      }
      
      for (int j = 0; j < setValue[index2].size(); j++) 
        {
          insert(set_num1,setValue[index2][j]);
        }
      return setValue[index1].size();
    }

    int Intersection(int set_num1,int set_num2)
    {
      int index2 = get_index(set_num2,setName,setName.size());
      int index1 = get_index(set_num1,setName,setName.size());
      if (index1==-1)
      {
            setName.push_back(set_num1);
            index1 = setName.size() - 1;
            setValue.push_back(vector<int>());
            return 0;
            
      }
      if (index2==-1)
      {
            setName.push_back(set_num2);
            index2 = setName.size() - 1;
            setValue.push_back(vector<int>());
            return 0;
      }
      
      vector<int> intSet;
      for (int i = 0; i < setValue[index2].size(); i++) 
      {
        if (BelongsTo(set_num1, setValue[index2][i]) == 1) 
        {
            intSet.push_back(setValue[index2][i]);
        }
      }

    
      setValue[index1] = intSet;

      return setValue[index1].size();
    }
  int Difference(int set_num1,int set_num2)
    {
      int index2 = get_index(set_num2,setName,setName.size());
      int index1 = get_index(set_num1,setName,setName.size());
      if (index1==-1)
      {
            setName.push_back(set_num1);
            index1 = setName.size() - 1;
            setValue.push_back(vector<int>());
            return 0;
            
      }
      if (index2==-1)
      {
            setName.push_back(set_num2);
            index2 = setName.size() - 1;
            setValue.push_back(vector<int>());
            return setValue[index1].size();
      }
      if(set_num1==set_num2)
      {
        vector <int> newest;
        
        setValue[index1]=newest;
        return 0;
      }
      
      vector<int> intSet;
      for (int i = 0; i < setValue[index1].size(); i++) 
      {
        if (BelongsTo(set_num2, setValue[index1][i]) == 0) 
        {
            intSet.push_back(setValue[index1][i]);
        }
      }

    
      setValue[index1] = intSet;

      return setValue[index1].size();
    }

    int SymmDiff(int set_num1,int set_num2)
    {
      
      
      int index2 = get_index(set_num2,setName,setName.size());
      int index1 = get_index(set_num1,setName,setName.size());
      if (index1==-1)
      {
            setName.push_back(set_num1);
            index1 = setName.size() - 1;
            setValue.push_back(vector<int>());
            return setValue[index2].size();
            
      }
      if(set_num1==set_num2)
      {
        vector <int> newest;
        
        setValue[index1]=newest;
        return 0;
      }
      if (index2==-1)
      {
            setName.push_back(set_num2);
            index2 = setName.size() - 1;
            setValue.push_back(vector<int>());
            return setValue[index1].size();
      }
      
      vector<int> copy1;
      vector<int> copy2;
      copy1=setValue[index1];
      copy2=setValue[index2];
      vector <int> unity;
      vector <int> inter;
      Union(set_num1,set_num2);
      unity=setValue[index1];
      setValue[index1]=copy1;
      Intersection(set_num1,set_num2);
      inter=setValue[index1];

      setValue[index1]=unity;
      setValue[index2]=inter;
      Difference(set_num1,set_num2);
      setValue[index2]=copy2;

      return setValue[index1].size();


    }

    
    
};


int main() 
{
    SET x;
    
    int cmd,num1,dat,num2;
    
    
    while (cin>>cmd)
    {
      
      
      if(cmd==1)
      {
        cin>>num1>>dat;
        
        int y=x.insert(num1,dat);
        cout<<y<<"\n";

      }
      else if (cmd==2)
      {
        cin>>num1>>dat;
        int y=x.Delete(num1,dat);
        cout<<y<<"\n";
      }
      else if(cmd==3)
      {
        cin>>num1>>dat;
        int y=x.BelongsTo(num1,dat);
        cout<<y<<"\n";
      }
      else if(cmd==4)
      {
        cin>>num1>>num2;
        int y=x.Union(num1,num2);
        cout<<y<<"\n";
      }
      else if(cmd==5)
      {
        cin>>num1>>num2;
        int y=x.Intersection(num1,num2);
        cout<<y<<"\n";
      }
      else if(cmd==6)
      {
        cin>>num1;
        
        int y=x.size(num1);
        cout<<y<<"\n";
      }
      else if(cmd==7)
      {
        cin>>num1>>num2;
        int y=x.Difference(num1,num2);
        cout<<y<<"\n";
      }
      else if(cmd==8)
      {
        cin>>num1>>num2;
        int y=x.SymmDiff(num1,num2);
        cout<<y<<"\n";
      }
      else if(cmd==9)
      {
        cin>>num1;
        x.print(num1);
      }
      
      
    }
    
}
