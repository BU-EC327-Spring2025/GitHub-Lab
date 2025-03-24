# GitHub-Lab
This lab assignment will introduce you to basic Git and GitHub concepts.

## Submission Instructions
This lab will be submitted as a pull request on GitHub.

## Instructions
1. Clone this repository to your local device
```
git clone git@github.com:BU-EC327-Spring2025/GitHub-Lab.git
```
2. Change current working directory to one that was just cloned
```
cd GitHub-Lab
```

3. List all the branches
```
git branch
```

4. Create a new branch called `<your-github-username>-lab` and switch to it
```
git branch <your-github-username>-lab
git checkout <your-github-username>-lab
```

5. Create an empty file called `<your-github-username>.txt` in the root of your repository
```
touch <your-github-username>.txt
```

6. Check the state of the working directory and the staging area
```
git status
```

7. Stage these changes
```
git add <your-github-username>.txt
```
Alternatively add all files with changes by doing `git add .`

8. Check the state of the working directory and the staging area
```
git status
```
If needed you can unstage a file by doing `git restore --staged <file-you-dont-want-commited>`

9. Commit the changes
```
git commit -m "<Write a message here that explains the changes you made at a high level>"
```

10. Check the commit log to see the history of commits
```
git log
```

11. Push these changes to the remote repository
```
git push --set-upstream origin <your-github-username>-lab
```
`--set-upstream origin <your-github-username>-lab` links your local branch to a e remote repository and sets it as the default remote branch for push and pull operations. The next time you push to the remote repository you can do `git push`


12. Now confirm that the changes appear on the remote repository and that the unit tests fail.

13. 
