func findCenter(edges [][]int) int {
    deg := make(map[int]int)
    for _, edge := range edges {
        for _, node := range edge {
            deg[node]++
        }
    }
    star, freq := 0, 0
    for node, cnt := range deg {
        if freq < cnt {
            freq = cnt
            star = node
        }
    }
    return star
}