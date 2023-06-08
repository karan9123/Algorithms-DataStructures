# Stable Matching

### **GOAL:**

Given a set of preferences among two parties(Hospitals and residents, men and women seeking parter for marriage), the goal is to find a matching where there are no two participants who would both prefer to be matched with each other rather than their current partners.

#
## **Gale-Shapely Algorithm**

This is a propose and reject algorthim. The algorithm ensures that the party doing the asking gets the best result for them.

**For eg:** If Hospitals are asking for residents then they get the best match for themselves, which may or may not be best match for residents. 

Best match here refers to the higher rank preference of the party.

### **Pseudocode:**

```
initialize each hospital to be free
while(Some hospital is free and hasn't asked all residents){
    choose such a hospital h
    r = first resident on h's list which hasn't been asked yet
    if (r is free){
        match h and r
    }else if (r prefers the current hospital h to already assigned h'){
        match h and r, h' is free now
    }else{
        r rejects h
    }
}
```