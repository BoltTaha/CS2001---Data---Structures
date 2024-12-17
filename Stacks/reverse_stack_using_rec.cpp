




void inseet_at_bottom(stack<int> &s,int ele)
{
    if(s.empty())
    {
        s.push(ele);
        return;
    }

    int hold = s.top();
    s.pop();

    inseet_at_bottom(s,ele);

    s.push(hold);
}

void rev_stack(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }

    int hold = s.top();
    s.pop();

    rev_stack(s);
    insert_at_bottom( s,hold);
}