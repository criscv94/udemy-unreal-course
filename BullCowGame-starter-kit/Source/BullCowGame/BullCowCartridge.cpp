// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    if (bGameOver) 
    {
        ClearScreen();
        SetupGame();
    }
    else // Checking PlayerGuess
    {
        if (Input == HiddenWord)
        {
            PrintLine(TEXT("You win!"));
            EndGame();
        }
        else 
        {
            if (HiddenWord.Len() != Input.Len())
            {
                PrintLine(TEXT("Ups, the HiddenWord is %i characters long. \nYou have lost!"), HiddenWord.Len());
            }
            else
            {
                PrintLine(TEXT("You lose!"));
                EndGame();
            }
        }
    }
    // Is an Isogram
    // Promt To GuessAgain
    // Is the right length?
    // Promt To GuessAgain
    // Remove Lives

    // Check lives > 0
    // Show Lives Left
    // If yes, GuessAgain, else Show GameOver and HiddenWord?
    // Prompt to Play Again, Press Enter to Play Again?
    // Check User Input
    // PlayAgain or Quit
}

void UBullCowCartridge::SetupGame()
{
    PrintLine(TEXT("Welcome to Bull Cows Game!"));
    HiddenWord = TEXT("tesla");
    Lives = 3;
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("Type your guess. \nPress enter to continue..."));
    bGameOver = false;
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again."));
}