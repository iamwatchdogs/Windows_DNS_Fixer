# Windows_DNS_Fixer  <img src="https://github.com/iamwatchdogs/Windows_DNS_Fixer/actions/workflows/code_linting.yml/badge.svg" alt="" align="right">

<br>
<div align="center">

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Visual Studio Code](https://img.shields.io/badge/Visual%20Studio%20Code-0078d7.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white)
![Windows Terminal](https://img.shields.io/badge/Windows%20Terminal-%234D4D4D.svg?style=for-the-badge&logo=windows-terminal&logoColor=white)
![Windows](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)

<br>

[![Open Source](https://badges.frapsoft.com/os/v1/open-source.svg?v=103)](https://github.com/iamwatchdogs?tab=repositories&q=&type=public&language=&sort=)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](https://github.com/iamwatchdogs/Windows_DNS_Fixer/pulls)
[![GitHub issues](https://img.shields.io/github/issues/iamwatchdogs/Windows_DNS_Fixer.svg)](https://github.com/iamwatchdogs/Windows_DNS_Fixer/issues)
[![GitHub pull-requests merged](https://badgen.net/github/merged-prs/iamwatchdogs/Windows_DNS_Fixer)](https://github.com/iamwatchdogs/Windows_DNS_Fixer.js/pulls?q=is%3Amerged)
[![GitHub release](https://img.shields.io/github/release/iamwatchdogs/Windows_DNS_Fixer)](https://GitHub.com/iamwatchdogs/Windows_DNS_Fixer/releases/)
[![License](https://img.shields.io/badge/License-Apache_2.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

</div>
<br>

Let me tell you about a fun little project I worked on a while back. It was a basic C program that automated the linear execution of some commands to fix the DNS issue in Windows OS. It was nothing fancy, just a few lines of code that made life a bit easier.

Recently, I stumbled upon this old project and I realized that I could take it to the next level. So, I got to work and improved it in ways I never thought possible. It was like rediscovering an old friend and bringing them back to life.

As I worked on it, I had a lot of fun playing around with the code and trying out new things. It was like a puzzle that I couldn't put down. I kept tweaking and refining until it was just right.

Now, I'm proud to say that my little project has grown into something that I hope people will find useful and educational. It's a testament to the power of curiosity and the joy of creation. Who knew that something as simple as fixing a DNS issue could lead to such a fulfilling journey?

# Troubleshooting:

This Repository is mainly focused on solving the DNS issue which looks similar to this one:

<div align="center">
  <br />
  <img src="https://i.insider.com/6261b053db73840018a579f2?width=700" alt="Not Internet - DNS not responding" >
  <br />
</div>

If you're facing similar problem, Then your first approach is to manually change your DNS address to Google's DNS hosting address which is `8.8.8.8` or `8.8.4.4` and restart your system.

Even after that you're facing an issue, then you can use the following commands to (in laymen terms) refresh your DNS.

```cmd
ipconfig /flushdns
ipconfig /registerdns
ipconfig /release
ipconfig /renew
NETSH winsock reset catalog
NETSH int ipv4 reset reset.log
NETSH int ipv6 reset reset.log
```

These were the commands which are used within the program. This mini-projects automates execution of all these statements one-by-one. Thus saving lots of your time...

> If you're a beginner and unable to follow up with the troubleshootin, checkout [THE_FIRST_STEP.md](THE_FIRST_STEP.md "Goto THE_FIRST_STEP.md") documentation for detailed step-by-step process.

## Contribution:

Even though this was a small mini-project which automates a couple of commands, We can take it to the next level. If you're a beginner and don't understand what contributing is... then hear me out, Contributing is a process where you wish to work on others' projects to implement your idea *(or)* fix errors to help/support others and improve your practical knowledge in that field. Contributing to an Open-Source such as this mini-project can help you in the long run of your technical journey. You can check [CONTRIBUTION.md](CONTRIBUTION.md "Let's go to CONTRIBUTION.md") for a more practical explanation.

To contribute to **this** repository, You need to have a good grip on the following skills:

- ***GitHub**. 

  > You need to have a basic understanding of how GitHub works.
  
- ***Git**.

  > Git acts as the local Version control and helps you connect your system with GitHub.
  
- ***C**.

  > C programming Language
  
- Other tech skills.

  > for example, understanding and using Windows API and stuff...

You can get started by forking this repo and cloning it into your system. Here are some of the git commands you'll be using,

```bash
# Clone your forked repo into your local system
git clone https://github.com/<Your-GitHub-Name>/Windows_DNS_Fixer.git

# Creating a new branch
git checkout -b <branch-name>

# Adding all the elements/changes into tracked/staged state
git add .

# Committing your every change
git commit -m "<message>"

# Updating your remote repo (or) pushing your commits to your forked repo
git push origin <branch-name>
```

After you're done with your changes, you can push them back to your remote repository. So that you can send me a pull request to merge the changes into the original Repository.

> Sounds too Complicated ???... Don't worry, checkout the beginner-friendly guide on how to contribute to this repo on [CONTRIBUTION.md](CONTRIBUTION.md "Let's goto CONTRIBUTION.md")
