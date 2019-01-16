package main

import "fmt"

func twoSum(nums []int, target int) []int {
    lenNums := len(nums)
    
    for i:=0; i < lenNums; i++ {
        for j:=i+1; j < lenNums; j++ {
            if nums[i] + nums[j] == target {
                return []int{i, j}
            }
        }
    }
    
    return []int{}
}

func main() {
    var nums  = []int{1, 2, 3, 5}
    var result []int
    var i int
    target := 5
    
    result = twoSum(nums, target)
    for i = 0; i < 2; i++ {
        fmt.Println(result[i])
    }
}