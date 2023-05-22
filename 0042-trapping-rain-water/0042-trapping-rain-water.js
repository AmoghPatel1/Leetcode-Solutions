/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    let left = 0, right = height.length-1;
    let leftMax = 0, rightMax = 0, ans = 0;
    
    while(left <= right) {
        if(height[left] <= height[right]) {
            if(height[left] >= leftMax) leftMax = height[left];
            else ans += leftMax - height[left];
            left += 1;
        } else {
            if(height[right] >= rightMax) rightMax = height[right];
            else ans += rightMax - height[right];
            right -= 1;
        }
    }
    return ans;
};