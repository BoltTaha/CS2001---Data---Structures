



void insert_at_bottom(stack<int> s,int val)
{
    if(s.empty())
    {
        s.push(val);
    }

    int hold = s.top();
    s.pop();

    insert_at_bottom(s,val);

    s.push(val);
}