# minitalk

### Table of Contents
* **About the project**
* * [Introduction](#introduction)
* **Usage**
* * [Requirements](#requirements)
* * [Instructions](#instructions)
* [**Goals**](#goals)
* [**Skills**](#skills)

## About the project

### Introduction

The purpose of this project is to code a small data exchange program using UNIX signals. It is an introductory project for the bigger UNIX projects that will appear later on in the cursus.

## Usage

### Requirements

The function is written in C language and thus needs the  **`gcc`  compiler**  and some standard  **C libraries**  to run.

### Instructions

**Cloning the repositories**

```shell
git clone https://github.com/Nera-tv/minitalk.git minitalk
make
```
**Run the program**

Run in one shell: 
```shell
./server
```
Copy the PID and run in another shell :

```shell
./client <PID> "your message"
```

## Goals:

-	Unix logic

## Skills:

- Rigor  
- Unix
