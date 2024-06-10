
long long FindGCD(long long _InA, long long _InB)
{
    long long Temp = 0;
        
    while (_InB != 0) 
    {
        Temp = _InA % _InB;
        _InA = _InB;
        _InB = Temp;
    }
    
    return _InA;
}

long long solution(int _InW,int _InH) {
    long long Answer = 0;

    long long LongWidth = _InW;
    long long LongHeight = _InH;

    if (LongWidth == LongHeight) 
    {
        // 정사각형 모양이면 직선은 항상 한 변의 길이만큼의 개수가 된다.
        Answer = (LongWidth * LongHeight) - LongWidth;
    }
    else
    {   
        // 전체 사각형 수에서
        Answer = (LongWidth * LongHeight);
        
        // (가로 + 세로 - 최대 공약수)를 제거하면 선이 차지하는 사각형이 제거된다.
        long long GCD = FindGCD(LongWidth, LongHeight);
        Answer -= ((LongWidth + LongHeight) - GCD);
    }


    return Answer;
}