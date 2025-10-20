1. Question is Long story short Will be Given a Logs messages Each Message is like String + timestamp
Intial Question: Print only those messages if the same message is not present in last 10 seconds.(Used Simple map <string,int> and if a new message comes we see if message is present in map and if present see its previous timestamp if current is more than previous then only print again else dont )
Asked to code the approach and he made me modify structure of code according to his thoughts and expectation.

2. You’re given a string and a list of word replacements (replace a word with another starting from a given index). It was straightforward, but I initially overcomplicated it thinking I needed a Trie. Still, I ended up solving it.

3. You have a dictionary of string, example - [string, sring, sing, wording, ing,ng, g]
You need to tell the maximum longest word in the dictionary that is valid.
Definiton of valid string , if you remove only one character from the string and it should be in the dictionary and by doing so if you able to reach at the end with length as 1, it will be valid.
Example - ( string-> sring->sing->ing->ng->g) [as all the intermediate string are present in the dictionary this will be a valid string and longest lenght is 6]



2-3 mins Intro 37minutes Interview Last 5 minutes for Questions
Always Walkthrough the code post writing code even if interviewer doesnt ask for code walkthrough.
L4 grading criteria is super tight so expectation is production ready code with handling every corner case.