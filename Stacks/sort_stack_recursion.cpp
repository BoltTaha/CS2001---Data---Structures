
void sort_stack(stack<int>)
{
    if(s.empty())
    {
        return;
    }

    int hold = s.top();
    s.pop();
    sort_stack(stack);
    sorted_insert(stack,hold);
}

void sorted_insert(stack<int> &s,int num)
{
    if(s.empty() || (!s.empty() && s.top() < num))
    {
        s.push(num);
        return;
    }
    int hold = s.top();
    s.pop();
    sorted_inserted(s,num);
    s.push(hold);
}