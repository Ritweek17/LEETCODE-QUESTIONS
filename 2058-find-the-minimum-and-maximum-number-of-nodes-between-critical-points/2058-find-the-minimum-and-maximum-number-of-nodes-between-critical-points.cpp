class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> critical;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int pos = 1;

        while (curr->next != NULL) {

            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {

                critical.push_back(pos);
            }

            prev = curr;
            curr = curr->next;
            pos++;
        }

        if (critical.size() < 2) {
            return {-1, -1};
        }

        int minDistance = INT_MAX;

        // Minimum distance between consecutive critical points
        for (int i = 1; i < critical.size(); i++) {
            minDistance = min(minDistance,
                              critical[i] - critical[i - 1]);
        }

        // Maximum distance = first to last critical point
        int maxDistance = critical.back() - critical.front();

        return {minDistance, maxDistance};
    }
};