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

12. Now confirm that the changes appear on the remote repository.

13. Create a pull request by going to the pull request tab and comparing your new branch to main. If you recently pushed a branch to the remote repository it may come up automatically and you can `Compare & pull request`. 

14. Once you have created a pull request, unit tests will automatically run. Observe what tests failed by viewing the details.

15. Now modify the files so the add function returns the correct output. Do this on the new branch you created.

16. Stage, commit, and push these changes to the remote repository. Since your pull request is still open, you should see your new commit come up in the pull request.

17. Confirm that unit tests pass.

18. Add ec327-staff as approvers.
19. This is the end of the lab. Usually one of the approvers will approve your PR and you can merge your changes into the main branch. The next time you work on another feature on your local device, you should `git pull` to get the new changes, and create a new branch based off main because the branch you merged is now outdated.

## Setting Up Automated Tests via GitHub Actions
Setting up GitHub Actions mainly consists of creating a file like `.github/workflows/ci.yml`. This defines the GitHub Actions workflow that builds and tests your project. Here is an example:
```
name: run-tests

on:
  pull_request:
    branches:
      - main
  
jobs:
  build:
    name: unit-tests
    runs-on: ubuntu-latest

    steps:
    - name: Checkout code
      uses: actions/checkout@v2

    - name: Install dependencies
      run: sudo apt-get update && sudo apt-get install -y cmake g++ libgtest-dev

    - name: Configure and Build
      run: |
        cmake -S . -B build
        cmake --build build

    - name: Run Tests
      run: ./build/test_add
```
- You can see that we have specified the `run-tests` workflow to run when there is a pull request on main. There is only one job specified: build and it is renamed to `unit-tests` for readability. It will also appear as `unit-tests` on GitHub Actions. We also specify the environment to be the latest version of Ubuntu provided by GitHub.
- `Checkout code` pulls the latest commit of the branch that triggered the workflow
- `Install dependencies` executes a shell command that installs necessary packages
- `Configure and Build` generates build files from `CMakeLists.txt` and compiles the project
- `Run Tests` executes the binary created from the previous step
#### Other Important Files
- `CMakeLists.txt` configures the build system and sets up the compilations of the test executable. This is how the project is build and links GTest.
- You will also need test files to run unit tests and source code like your .h and .cpp files.
- `.gitignore` can include files like the build directory so build artifacts and temporary files can be ignored

#### Example Directory Structure
Your directory structure might look something like this:
```
/git-lab-demo
├── /include
│   └── add.h             # Header file with function declarations
├── /src
│   └── add.cpp           # Source file with function definitions
├── /tests
│   └── test_add.cpp      # Google Test for unit tests
├── /.github
│   └── /workflows
│       └── ci.yml               # GitHub Actions CI configuration
├── /build                       # Generated build directory (ignored in .gitignore)
├── /CMakeLists.txt              # CMake configuration
└── /README.md                   # Project documentation
```
To require unit tests to pass before merging a branch, it is important to trigger the workflow, so it comes up in GitHub settings. After it has triggered once, navigate to `Settings`->`Branches`->`Add Classic Branch Protection Rule`, then check `Require status checks to pass before merging` and search for the status checks with that name you have defined in the `yml` file.

