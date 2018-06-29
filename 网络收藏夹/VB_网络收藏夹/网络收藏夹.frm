VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Õ¯¬Á ’≤ÿº–"
   ClientHeight    =   3015
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   4560
   LinkTopic       =   "Form1"
   ScaleHeight     =   3015
   ScaleWidth      =   4560
   StartUpPosition =   3  '¥∞ø⁄»± °
   Begin VB.CommandButton Command4 
      Caption         =   "+"
      Height          =   375
      Left            =   3840
      TabIndex        =   3
      Top             =   120
      Width           =   615
   End
   Begin VB.CommandButton Command3 
      Caption         =   "±‡º≠"
      Height          =   495
      Index           =   0
      Left            =   2880
      TabIndex        =   2
      Top             =   480
      Width           =   855
   End
   Begin VB.CommandButton Command2 
      Caption         =   "œÍœ∏–≈œ¢"
      Height          =   495
      Index           =   0
      Left            =   1800
      TabIndex        =   1
      Top             =   480
      Width           =   855
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Õ¯÷∑“ª"
      Height          =   495
      Index           =   0
      Left            =   120
      TabIndex        =   0
      Top             =   480
      Width           =   1455
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click(Index As Integer)

End Sub

Private Sub Command4_Click()
    Form1.Hide
    Form2.Show
    Dim I As Integer
    I = 1
    Load Command1(I)
    Command1(I).Visible = True
    Command1(I).Top = Command1(I).Top + 600
    
    Load Command2(I)
    Command2(I).Visible = True
    Command2(I).Top = Command2(I).Top + 600
    
    Load Command3(I)
    Command3(I).Visible = True
    Command3(I).Top = Command3(I).Top + 600
End Sub

