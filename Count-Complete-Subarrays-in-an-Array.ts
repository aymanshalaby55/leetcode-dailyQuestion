function countCompleteSubarrays(nums: number[]): number {
    const mp = new Set();
    const sub = new Set();
    for (let i of nums) {
        mp.add(i);
    }

    let ans = 0;
    for (let i = 0; i < nums.length; i++) {
        let dis2 = 0;
        for (let j = i; j < nums.length; j++) {
            
            sub.add(nums[j]);
            if (mp.size === sub.size) {
                ans++;
            }
        }
        sub.clear();
    }
    return ans;
};