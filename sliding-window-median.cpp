template <class RandomIt>
double median(RandomIt begin, RandomIt end)
{
    assert(begin != end);
    auto size = end - begin;
    auto middleIdx = size / 2;
    auto target = begin + middleIdx;
    nth_element(begin, target, end);

    if (size % 2 != 0)
    {
        return *target;
    }
    else
    {
        double a = *target;
        auto targetNeighbor = target - 1;
        nth_element(begin, targetNeighbor, end);
        return (a + *targetNeighbor) / 2.;
    }
}

class MedianTracker
{
    deque<int> _values;
    unsigned int _capacity;

  public:
    MedianTracker(unsigned int capacity)
    {
        _capacity = capacity;
    }
    void AddValue(int value)
    {
        _values.push_back(value);
        if (_values.size() > _capacity)
        {
            _values.pop_front();
        }
    }
    double GetMedian()
    {
        vector<int> values;
        for (const auto &value : _values)
        {
            values.push_back(value);
        }
        return median(values.begin(), values.end());
    }
};

class Solution
{
  public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        MedianTracker tracker(k);
        vector<double> result;
        for (int i = 0; i < nums.size(); ++i)
        {
            tracker.AddValue(nums[i]);
            if (i >= k - 1)
            {
                result.push_back(tracker.GetMedian());
            }
        }
        return result;
    }
};
