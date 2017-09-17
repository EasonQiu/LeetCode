// There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

// Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

// Note:
// The solution is guaranteed to be unique.

// 关键只要考虑gas和cost之间的diff就行
// If car starts at A and can not reach B. Any station between A and B
// can not reach B.(B is the first station that A can not reach.)
//      证明B之前的几站能reach说明每站的初始gas>=0，这种情况下都无法到达B。那么gas从0开始一定也到不了B
// If the total number of gas is bigger than the total number of cost. There must be a solution.
//      证明把circle分割成两部分，一部分[i, j]有min subsum，这时你可以保证从j + 1开始走到i - 1有至少-subsum的油量
class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  	// sum 表示从0位置开始走完全程需要缺多少gas
  	int sum = 0, gas_left = 0, start = 0;
  	for (int i = 0; i < gas.size(); ++i) {
  		// how much gas left when you reach the next station
  		gas_left += gas[i] - cost[i];
  		if (gas_left < 0) {
  			sum += gas_left;  gas_left = 0;
  			start = i + 1;
  		}
  	}
  	return (sum + gas_left >= 0) ? start : -1;
  }
};