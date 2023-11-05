
### NO BUFF
[Count: 30] [Loops: 100'000'000]
  - SOA:            `~5.8s`
  - AOS:            `~5.8s` 
  - AOS Of Ptrs:    `~5.8s` 
[Count: 1'000'000] [Loops: 3'000]
  - SOA:             `~5.4s`
  - AOS:             `~5.4s` 
  - AOS Of Ptrs:     `~12s` 
[Count: 100'000'000] [Loops: 30]
  - SOA:             `~6s`
  - AOS:             `~8s` 
  - AOS Of Ptrs:     `~27s` 
  
### EXTRA BUFF 64B
[Count: 30] [Loops: 100'000'000]
  **Kinda same**
  - SOA:             `~5s`
  - AOS:             `~19.3s` 
  - AOS Of Ptrs:     `~5.1s` 
[Count: 1'000'000] [Loops: 3'000]
  - SOA:             `~3.2s`
  - AOS:             `~31s` 
  - AOS Of Ptrs:     `~64s` 
[Count: 100'000'000] [Loops: 30]
  - SOA:             `~4s`
  - AOS:             `~24s` 
  - AOS Of Ptrs:     `~48s`