VERSION 5.00
Begin VB.Form Form2 
   Caption         =   "添加/更改网址"
   ClientHeight    =   3015
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   4560
   LinkTopic       =   "Form2"
   ScaleHeight     =   3015
   ScaleWidth      =   4560
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command1 
      Caption         =   "完成"
      Height          =   375
      Left            =   1200
      TabIndex        =   6
      Top             =   2400
      Width           =   1575
   End
   Begin VB.TextBox Text3 
      Height          =   495
      Left            =   1560
      TabIndex        =   5
      Top             =   1560
      Width           =   2055
   End
   Begin VB.TextBox Text2 
      Height          =   495
      Left            =   1560
      TabIndex        =   4
      Top             =   720
      Width           =   2055
   End
   Begin VB.TextBox Text1 
      Height          =   495
      Left            =   1560
      TabIndex        =   3
      Top             =   120
      Width           =   2055
   End
   Begin VB.Label Label3 
      Caption         =   "详细信息"
      Height          =   375
      Left            =   240
      TabIndex        =   2
      Top             =   1680
      Width           =   855
   End
   Begin VB.Label Label2 
      Caption         =   "描述："
      Height          =   255
      Left            =   240
      TabIndex        =   1
      Top             =   840
      Width           =   855
   End
   Begin VB.Label Label1 
      Caption         =   "网址："
      Height          =   255
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   855
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()

Dim I As Integer

Command1.Caption = Text1.Text
Rem Command2(I).Caption = Text1.Text
Rem Command3(I).Caption = Text1.Text
Unload Me
Form1.Show

End Sub

