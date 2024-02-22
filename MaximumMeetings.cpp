You are given the schedule of 'N' meetings with their start time 'Start[i]' and end time 'End[i]'.
You have only 1 meeting room. So, you need to return the maximum number of meetings you can organize.
Note:
The start time of one chosen meeting can’t be equal to the end time of the other chosen meeting.

//code

struct meet{
    int meetingID;
    int startTime;
    int endTime;
};

bool compare (struct meet a, struct meet b)
{
    if(a.endTime == b.endTime){
        return a.meetingID < b.meetingID;
    }
    else{
        return a.endTime < b.endTime;
    }
}

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    struct meet meeting[n];

    for(int i =0;i<n;i++){
        meeting[i].meetingID = i+1;
        meeting[i].startTime = start[i];
        meeting[i].endTime = end[i];

    }

    sort(meeting,meeting+n,compare);

    int ans = 1;
    int currentTime = meeting[0].endTime;

    for(int i=1;i<n;i++){
        if(meeting[i].startTime > currentTime){
            ans++;
            currentTime = meeting[i].endTime;
        }
    }
    return ans;
}