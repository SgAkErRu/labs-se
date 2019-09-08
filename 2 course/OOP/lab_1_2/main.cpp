#include <iostream>
#include <string>
#include "Triangle.h"


using namespace std;

int main()
{
    /// ����������� 2, 4, 5: S = 3.8, P = 11, ����: 108.21; 22.33; 49.46; ha 3.8; hb 1.9; hc 1.52
    /// ����������� 3, 4, 5: S = 6, P = 12, ����: 90; 36.87; 53.13; ha 4; hb 3; hc 2.4;
    /// ����������� 3, 4, 6: S = 5.33, P = 13, ����: 117.28; 36.34; 26.38; ha 3.555; hb 2.666; hc 1.778;

    system("chcp 1251 > nul");
    cout << "������������ ������ �1. ������� 7.\n�����: ������� ������. �����-21.\n" << endl;
    cout << "������ 2." << endl;
    cout << "�������: ����������� ����� Triangle, �������������� ����� ����������� �� ���������, ������������ �� ���� ��������." << endl << endl;
    cout << "��������� ����������� ��������� ������: ���������� ������� � ���������, ����������� ���� ������������, ���������� �����, ���������� �����, ��������� ������������� �� ������� � �� ���������, ����������� ������� ������������� �� ���� ��������." << endl << endl;

    try // ���� ����������, ������� ������������� � ����� try � ���������� �� ��� ��������� � ����(�) catch
    {
        cout << "1. �������� ������������ Tri1, ������������� ���������� 2, 4, 5 � ����������� ����� ������������ Tri1." << endl;
        Triangle Tri1(2,4,5);
        Tri1.Display();
        cout << "\n������ ������ � ������: "; // � ������ pragma pack (1) ����� ����� �� ������, ��� ��� ��� ��� ���� ������ ������ ���� double
        cout << sizeof(Tri1) << endl;
        cout << "\n2. �������� ������������ Tri2, ������������� ���������� ���������� � ����������." << endl;
        Triangle Tri2;
        Tri2.Read();
        Tri2.Display();
        cout << "\n3. �������� ������������ Tri3, ������������� �������� Tri2 � ����������� ����� Tri3." << endl;
        Triangle Tri3 = Tri2;
        Tri3.Display();
        cout << "\n4. ����� ��������� ������������ Tri3: ";
        cout << Tri3.FindPerimeter() << endl;
        cout << "\n5. ����� ������� Tri3: ";
        cout << Tri3.FindSquare() << endl;
        cout << "\n6. ����������� ���� ������������ Tri3: " << endl;
        Tri3.TriangleKind();
        cout << "\n7. ���������� ����� ������������ Tri3: " << endl;
        Tri3.FindHeight();
        cout << "\n8. ���������� ����� ������������ Tri3: " << endl;
        Tri3.DisplayAngles();
        cout << "\n9. ��������� ������������ Tri3 � Tri1: " << endl;
        Tri3.CompareTwoTriangles(Tri1);
        cout << "\n10. ����������� ������� ������������� Tri3 � Tri1: " << endl;
        Tri3.Podobie(Tri1);

    }
    catch (const char* exception) // ��������� ���������� ���� const char*
    {
        cerr << "������: " << exception << endl;
    }
    return 0;
}
