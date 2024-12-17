void insert_at_bottom(stack<int> &s,int num)
{
    if(s.empty())
    {
        s.push(num);
        return; 
    }
    int hold = s,top();
    s.pop();
    insert_at-bottom(s,num)
    s.push(hold);
}

void reverse_stack(stack<int> &s)
{
    if(s.empty())
    {return;}
    
    int hold = s.top();
    s.pop();
    
    reverse_stack(stack);
    insert_at_bottom(stack,hold);
}
