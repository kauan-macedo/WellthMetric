#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void clear_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

char get_language()
{
    char language;
    printf("Select the language:\n");
    printf("Escolha o idioma:\n");
    printf("P - Português\n");
    printf("E - English\n");
    language = toupper(getchar());
    printf("\n");
    clear_buffer();
    return language;
}

char get_unit_system()
{
    char unit_system;
    printf("Select the unit system:\n");
    printf("Escolha o sistema de unidades:\n");
    printf("M - Metric (Kg, meters)\n");
    printf("I - Imperial (lbs, feet and inches)\n");
    unit_system = toupper(getchar());
    printf("\n");
    clear_buffer();
    return unit_system;
}

void get_name(char *name, char language)
{
    int tries = 0;
    do
    {
        if (tries > 0)
        {
            if (language == 'P')
                printf("Nome inválido. Por favor, insira um nome com mais de 2 caracteres e menos de 50 caracteres.\n\n");
            else
                printf("Invalid name. Please enter a name with more than 2 characters and less than 50 characters.\n\n");
        }
        if (language == 'P')
            printf("Caro usuário, qual é o seu nome?\n");
        else
            printf("Dear user, what is your name?\n");
        fgets(name, 51, stdin);
        name[strcspn(name, "\n")] = '\0';
        printf("\n");
        tries++;
    } while ((strlen(name) <= 2) || (strlen(name) > 50));
}

float get_weight(char language, char unit_system)
{
    char weight_str[7];
    float weight;
    int tries = 0;
    do
    {
        if (tries > 0)
        {
            if (language == 'P')
                printf("Peso inválido. Por favor, insira um valor numérico entre 0 e 1408 (lbs) ou 0 e 640 (Kg).\n\n");
            else
                printf("Invalid weight. Please enter a numeric value between 0 and 1408 (lbs) or 0 and 640 (Kg).\n\n");
        }
        if (language == 'P')
            printf("Digite seu peso em %s\n", unit_system == 'M' ? "Kg" : "lbs");
        else
            printf("Enter your weight in %s\n", unit_system == 'M' ? "Kg" : "lbs");
        fgets(weight_str, sizeof(weight_str), stdin);
        weight_str[strcspn(weight_str, "\n")] = '\0';
        char *endptr;
        weight = strtof(weight_str, &endptr);
        if (endptr == weight_str || *endptr != '\0')
        {
            weight = -1;
        }
        printf("\n");
        tries++;
    } while ((weight <= 0) || (weight > (unit_system == 'M' ? 640 : 1408)));
    return weight;
}

float get_height_metric(char language)
{
    char height_str[4];
    float height;
    int tries = 0;
    do
    {
        char *endptr;
        if (tries > 0)
        {
            if (language == 'P')
                printf("Altura inválida. Por favor, insira um valor numérico entre 0 e 2,60 (meters).\n\n");
            else
                printf("Invalid height. Please enter a numeric value between 0 and 2.60 (meters).\n\n");
        }
        if (language == 'P')
            printf("Digite sua altura em metros\n");
        else
            printf("Enter your height in meters\n");
        fgets(height_str, sizeof(height_str), stdin);
        height_str[strcspn(height_str, "\n")] = '\0';
        height = strtof(height_str, &endptr);
        if (endptr == height_str || *endptr != '\0')
        {
            height = -1;
        }
        printf("\n");
        tries++;
    } while ((height <= 0) || (height > 2.60));
    return height;
}

float get_height_imperial(char language)
{
    char feet_str[3], inches_str[3];
    float feet, inches;
    int tries = 0;
    do
    {
        if (tries > 0)
        {
            if (language == 'P')
                printf("Altura inválida. Por favor, insira um valor numérico entre 0 e 8 (feet) e 0 e 11 (inches).\n\n");
            else
                printf("Invalid height. Please enter a numeric value between 0 and 8 (feet) and 0 and 11 (inches).\n\n");
        }
        if (language == 'P')
            printf("Digite sua altura em pés e polegadas\n");
        else
            printf("Enter your height in feet and inches\n");
        printf("Feet: ");
        fgets(feet_str, sizeof(feet_str), stdin);
        feet_str[strcspn(feet_str, "\n")] = '\0';
        char *endptr;
        feet = strtof(feet_str, &endptr);
        if (endptr == feet_str || *endptr != '\0')
        {
            feet = -1;
        }
        printf("Inches: ");
        fgets(inches_str, sizeof(inches_str), stdin);
        inches_str[strcspn(inches_str, "\n")] = '\0';
        inches = strtof(inches_str, &endptr);
        if (endptr == inches_str || *endptr != '\0')
        {
            inches = -1;
        }
        printf("\n");
        tries++;
    } while ((feet < 0 || feet > 8) || (inches < 0 || inches >= 12));
    return (feet * 12 + inches) * 0.0254; // Convert feet and inches to meters
}

void display_bmi_result(char *name, float bmi, char language)
{
    if (language == 'P')
        printf("\n=== Seu Resultado ===\n");
    else
        printf("\n=== Your Result ===\n");
    if (language == 'P')
        printf("%s, seu IMC é %.1f,", name, bmi);
    else
        printf("%s, your BMI is %.1f,", name, bmi);

    if (bmi < 18.5)
    {
        if (language == 'P')
            printf(" você está abaixo do peso\n");
        else
            printf(" you are underweight\n");
    }
    else if (bmi <= 24.9)
    {
        if (language == 'P')
            printf(" você está no peso ideal\n");
        else
            printf(" you are at the ideal weight\n");
    }
    else if (bmi <= 29.9)
    {
        if (language == 'P')
            printf(" você está com sobrepeso\n");
        else
            printf(" you are overweight\n");
    }
    else if (bmi <= 34.9)
    {
        if (language == 'P')
            printf(" você está com obesidade grau I\n");
        else
            printf(" you have Class I Obesity\n");
    }
    else if (bmi <= 39.9)
    {
        if (language == 'P')
            printf(" você está com obesidade grau II\n");
        else
            printf(" you have Class II Obesity\n");
    }
    else
    {
        if (language == 'P')
            printf(" você está com obesidade grau III (obesidade mórbida)\n");
        else
            printf(" you have Class III Obesity (morbid obesity)\n");
    }
}

char ask_to_continue(char language)
{
    char again;
    int tries = 0;
    do
    {
        if (tries > 0)
        {
            if (language == 'P')
                printf("\nOpção inválida. Por favor, responda com \"S\" para sim ou \"N\" para não.\n");
            else
                printf("\nInvalid option. Please respond with \"Y\" for yes or \"N\" for no.\n");
        }
        if (language == 'P')
            printf("\nDeseja continuar calculando? Responda com \"S\" ou \"N\"\n");
        else
            printf("\nDo you want to continue calculating? Respond with \"Y\" or \"N\"\n");
        again = toupper(getchar());
        clear_buffer();
        printf("\n");
        tries++;
    } while (again != 'S' && again != 'N' && again != 'Y');
    return again;
}

int main(void)
{
    char language = get_language();
    char unit_system = get_unit_system();
    char name[51];
    float weight, height, bmi;
    char again;

    do
    {
        get_name(name, language);
        weight = get_weight(language, unit_system);

        if (unit_system == 'I')
        {
            height = get_height_imperial(language);
            weight *= 0.453592; // lbs to kg
        }
        else
        {
            height = get_height_metric(language);
        }

        bmi = (weight / (height * height));
        display_bmi_result(name, bmi, language);

        again = ask_to_continue(language);
        if (again == 'S' || again == 'Y')
        {
            if (language == 'P')
                printf("\n-------NOVO CÁLCULO------------\n");
            else
                printf("\n-------NEW CALCULATION------------\n");
        }
    } while (again == 'S' || again == 'Y');

    if (language == 'P')
        printf("\nObrigado por usar a calculadora. Até logo!\n");
    else
        printf("\nThank you for using the calculator. See you soon!\n");

    return 0;
}
