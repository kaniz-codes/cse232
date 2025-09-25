# Asymptotic Notation

Assymptotic notation is a mathematical tool used to describe the performance (time or space complexity) of an algorithm.

## Types of Asympototic notation
- Big Oh (Upper Bound)
- Big Theta (Tight Bound)
- Big Omega (Lower Bound)

## Growth Rates (From Slowest to Fastest)

```css
1 < log n < √n < n < nlogn < n² < n³ < 2ⁿ < 3ⁿ < ... < nⁿ
 ^-------------- ^└─────────────────────────────────────
 └──Big-Omega    |       └── Big-O (Upper Bound)
                 |
                 └────────── Big-Theta (Tight Bound)

```
> [!NOTE]
> `n` belongs to both lower bound, tight bound and upper bound

## Difference between Big O, Big Theta and Big Omega

| Feature              | Big-O (O)                         | Big-Theta (Θ)                           | Big-Omega (Ω)                         |
|----------------------|----------------------------------|-----------------------------------------|--------------------------------------|
| Case                 | Worst Case                       | Average Case                            | Best Case                            |
| Growth Type          | Upper Bound                      | Tight Bound                              | Lower Bound                          |
| Meaning              | Maximum time an algorithm takes  | Exact/average time an algorithm takes   | Minimum time an algorithm takes      |
| Mathematical Form    | f(n) ≤ c·g(n), for n ≥ n₀         | c₁·g(n) ≤ f(n) ≤ c₂·g(n), for n ≥ n₀    | f(n) ≥ c·g(n), for n ≥ n₀            |
| Example Function     | f(n) = 5n² + 3n + 4               | f(n) = 5n² + 3n + 4                      | f(n) = 5n² + 3n + 4                  |
| Reference Function   | g(n) = n²                         | g(n) = n²                                | g(n) = n²                            |
| Constants            | c = 12, n₀ = 1                    | c₁ = 7, c₂ = 12, n₀ = 1                 | c = 5, n₀ = 1                        |
| Result               | f(n) ∈ O(n²)                      | f(n) ∈ Θ(n²)                             | f(n) ∈ Ω(n²)                         |


## Example
Here's example for Big-O (O), Big-Theta (Θ) and Big-Omega (Ω) 

### Big-O (O)

```css
f(n) ≤ c·g(n), for n ≥ n₀
f(n) = 5n² + 3n + 4
g(n) = n²
c = 12, n₀ = 1 
f(n) ∈ O(n²)
```

### Big-Theta (Θ) 

```css
c₁·g(n) ≤ f(n) ≤ c₂·g(n), for n ≥ n₀
f(n) = 5n² + 3n + 4
g(n) = n²
c₁ = 7, c₂ = 12, n₀ = 1 
f(n) ∈ Θ(n²)
```

### Big-Omega (Ω)

```css
f(n) ≥ c·g(n), for n ≥ n₀ 
f(n) = 5n² + 3n + 4
g(n) = n²
c = 5, n₀ = 1 
f(n) ∈ Ω(n²)
```

## Resources

Here are some of the sources I found useful while researching:

- [Abdul Bari](https://youtu.be/A03oI0znAoc?si=tEGx6kDAcXoct5QJ) 

- [learnxinyminutes](https://learnxinyminutes.com/asymptotic-notation/) 

- [geeksforgeeks](https://www.geeksforgeeks.org/dsa/types-of-asymptotic-notations-in-complexity-analysis-of-algorithms/)  

- [programiz](https://www.programiz.com/dsa/asymptotic-notations)  
