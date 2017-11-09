#!/bin/bash
#################################################################################
## Moulinette de norme Epitech				                       ##
##									       ##
## Made by de-dum_m & armita_a						       ##
## Login   <de-dum_m@epitech.net et armita_a@epitech.net>		       ##
## Version  0.4.3         						       ##
#################################################################################

##################################
##   variables editables        ##
##################################

USERNAME="Florac clement" # si votre username git est different de la variable #USER

##################################
##   declaration des couleurs   ##
##################################

WHITE="\033[0m"
RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[0;33m"
BLUE="\033[0;34m"
MAGENTA="\033[0;35m"
CYAN="\033[0;36m"

BOLD="\033[1m"
BRED="\033[1;31m"
BGREEN="\033[1;32m"
BYELLOW="\033[1;33m"
BBLUE="\033[1;34m"
BMAGENTA="\033[1;35m"
BCYAN="\033[1;36m"

##################################
##   declaration des variables  ##
##################################

FTEMP="$HOME/.config/norme/.temp"
TMP="$FTEMP/.tmp"
MAINDIR="$HOME/.config/norme"
TMP2="$FTEMP/.temp2"
TMP3="$FTEMP/.temp3"
TMP4="$FTEMP/.temp4"
TMP5="$FTEMP/.temp5"
TMP6="$FTEMP/.temp6"
TMP7="$FTEMP/.temp7"
TMP8="$FTEMP/.temp8"
TMP9="$FTEMP/.temp9"
TMP10="$FTEMP/.temp10"
TMP11="$FTEMP/.temp11"
TMP12="$FTEMP/.temp12"
TMP15="$FTEMP/.temp15"
TMP16="$FTEMP/.temp16"
NMTMP="$FTEMP/.temp1"

NB_ERROR=0
CM=0
COM=0
MALLOC=0

ALLOWED="$MAINDIR/$(echo "$PWD" | md5sum | awk '{print $1}')"
ALLOWED_U="$MAINDIR/$(echo "$PWD'users'" | md5sum| awk '{print $1}')"
PROJECT=`cat Makefile 2>/dev/null | grep -E "^NAME" | awk '{ print $NF }'`

function print_error() # imprime le message d'erreur
{
    echo -e $BRED"Erreur: $CYAN`basename $1`: $WHITE$2"
}

function print_triche() # imprime le message de triches
{
    echo -e $BCYAN"/***************************************\\ $WHITE"
    echo -e $BCYAN"|            $BRED TRICHE$BCYAN                     "
    echo -n "| "
    print_error $1 "$2          $BCYAN"
    echo -e $BCYAN"\                                       /$WHITE"
    echo -e $BCYAN"****************************************$WHITE"
}

function dot_h() # verifie les fichier header (.h)
{
    find $PWD -name "*.h" | grep -v '#'> $TMP2
    for HFILE in `cat $TMP2`; do
	echo -e $WHITE"Scan : "$BOLD"`basename $HFILE`"
	double_line $HFILE
	check_macro $HFILE
	nb_col $HFILE
	last_carac $HFILE
	check_header $HFILE
    done
}

function check_macro() # verifie les macro de protection des fichier header (.h)
{
    UNDER_SCORE="_"
    STR1=`basename $1 |tr '[a-z]' '[A-Z]' | sed 's/\./_/g'`
    STR="#ifndef $STR1$UNDER_SCORE"
    if [[ `head -n 11 $1 | tail -n 1` != $STR ]]
    then
	print_error $1 "macro $BMAGENTA`head -n 11 $1 | tail -n 1`$WHITE incorrect"
	NB_ERROR=$((NB_ERROR + 1))
    fi
    STR="# define $STR1$UNDER_SCORE"
    if [[ `head -n 12 $1 | tail -n 1` != $STR ]]
    then
	print_error $1 "macro $BMAGENTA`head -n 12 $1 | tail -n 1`$WHITE incorrect"
	NB_ERROR=$((NB_ERROR + 1))
    fi
    STR="#endif /* !$STR1$UNDER_SCORE */"
    if [[ `tail -n -1 $1` != $STR ]]
    then
	print_error $1 "macro $BMAGENTA`tail -n -1 $1`$WHITE incorrect"
	NB_ERROR=$((NB_ERROR + 1))
    fi
}

function check_makefile() # verifie la norme du Makefile
{
    echo -e $WHITE"Scan : "$BOLD"Makefile"$WHITE
    if [[ ! -f Makefile ]]; then
        echo -e $BRED"Makefile not found"
	return
    fi
    echo -e "##\n" > $TMP3
    local NAME=`cat Makefile | head -n 4| tail -n 1 | sed "s/## Made by //"`
    local NB=0
    for USER in `cat $ALLOWED_U`; do
	if [[ $NAME == $USER || $NAME == $USERNAME ]]; then
	    NB=1;
	fi;
    done
    if [[ $NB -eq 0 ]]
    then
	print_triche Makefile "mauvais header"
	NB_ERROR=$((NB_ERROR + 1))
    fi
    head -n 1 Makefile > $TMP4
    if [[ `cat $TMP4` != `cat $TMP3` ]]
    then
	print_error $1 "ligne 1 invalide"
	NB_ERROR=$(($NB_ERROR + 1))
    fi
    if [[ -z `cat Makefile | grep "(NAME)"` ]]; then
	print_error Makefile "pas de regle \$(NAME)"
	NB_ERROR=$(($NB_ERROR + 1))
    fi
    if [[ -z `cat Makefile | grep clean` ]]; then
	print_error Makefile "pas de regle clean"
	NB_ERROR=$(($NB_ERROR + 1))
    fi
    if [[ -z `cat Makefile | grep fclean` ]]; then
	print_error Makefile "pas de regle fclean"
	NB_ERROR=$(($NB_ERROR + 1))
    fi
    if [[ -z `cat Makefile | grep re` ]]; then
	print_error Makefile "pas de regle re"
	NB_ERROR=$(($NB_ERROR + 1))
    fi
    if [[ -z `cat Makefile | grep .PHONY` ]]; then
	print_error Makefile "pas de regle .PHONY"
	NB_ERROR=$(($NB_ERROR + 1))
    fi
    make re >/dev/null 2>/dev/null
    if [[ `make 2>/dev/null| wc -l` != 1 ]]; then
	print_error Makefile "qui relink ou qui compile pas"
	NB_ERROR=$(($NB_ERROR + 1))
    fi
    make clean >/dev/null 2>/dev/null
    if [[ `cat Makefile | grep "*"` ]]; then
	print_error Makefile "utilisation de wildcard"
	NB_ERROR=$(($NB_ERROR + 1))
    fi
}

function function_length() # verifie la longueur des fonctions (plus de 25 lignes)
{
    local VAR=`cat $1 | pcregrep -vM "^[a-z]+.*\(.*\)$\n\{(.*\n){1,26}^\}$" | grep -vE "(/\*|^\*\*|\*/|^#)" | pcregrep -vM "(^\n$){2,}" |  grep -Eo "[a-zA-Z_0-9]+\(.*\)$" | head -n1`
    if [[ ! -z $VAR ]]; then
	local TMP=`cat $1 | pcregrep -vM "^[a-z]+.*\(.*\)$\n\{(.*\n){1,26}^\}$" | grep -vE "(/\*|^\*\*|\*/|^#)" | pcregrep -vM "(^\n$){2,}"| pcregrep -vM "(^\}$\n+|\n+^\{$)"| wc -l`
	if [[ $TMP -gt 25 ]]; then
	    print_error $1 "$VAR: fonction de plus de 25 lignes"
	    NB_ERROR=$(($NB_ERROR + 1))
	fi
    fi
}

function nb_functions() # verifie le nombre de fonctins (plus de 5 par fichier)
{
    local NB_LINE=`cat $1 | grep "^[a-z]\{1,\}.*)$" | wc -l`
    if [[ $NB_LINE -gt 5 ]]
    then
	print_error $1 "$NB_LINE fonctions"
	NB_ERROR=$((NB_ERROR + 1))
    fi
}

function keyword_spaces() # verifie le espaces pres les mots cles (return | if | while)
{
    grep -En "\s+(return|if|while)\(" $1 > $TMP5
    while read VAR1; do
    	local N1VAR=`echo $VAR1 | awk '{print $1}' | sed 's/:/  /' | tr ":" " "`
    	local N3VAR=`echo $N1VAR | awk '{ print $NF}'`
    	print_error $1 "ligne $N3VAR: pas d'espace après mot clef"
    	NB_ERROR=$((NB_ERROR + 1))
    done < $TMP5
}

function check_header() # verifie le login du header
{
    echo -e "/*\n" > $TMP3
    local NAME=`cat $1 | head -n 4| tail -n 1 | sed "s/** Made by //"`
    local NB=0
    for USER in `cat $ALLOWED_U`; do
	if [[ $NAME == $USER || $NAME == $USERNAME ]]; then
	    NB=1;
	fi;
    done
    if [[ $NB -eq 0 ]]
    then
	#print_triche $1 "mauvais header"
	NB_ERROR=$((NB_ERROR + 1))
    fi
    head -n 1 $1 > $TMP4
    if [[ `cat $TMP4` != `cat $TMP3` ]]
    then
	print_error $1 "ligne 1 invalide"
	NB_ERROR=$(($NB_ERROR + 1))
    fi
}

function function_params() # verifie le nombre de parametres des fonctions (plus de 4)
{
    local VAR=`grep -nE "^[a-z]{1,}.*\((.*,){4,}.*\)$" $1`
    if [[ ! -z $VAR ]]; then
	local LINE=`echo $VAR | tr ":" " " | awk '{print $1}'`
	local FUNCT=`echo $VAR | tr ":" " " | grep -oE "[a-zA-Z_0-9]+\("`
	print_error $1 "ligne $LINE $FUNCT...): too many parameters"
	NB_ERROR=$((NB_ERROR + 1))
    fi
}

function allowed_functions() # verifie si les appels systemes sont autorises
{
    if [[ -f $PROJECT && -f `echo $PROJECT | grep -v "\.a$"` ]]; then
	local TEST=`nm -D $PROJECT | grep -v "U _" | grep -vE "^[0-9]" | grep -v "[a-z] .*" | sed 's/$*U //' | sed 's/ *//'`
	for FUNCT in $TEST; do
	    if [[ ` grep "#$FUNCT" $ALLOWED` ]]; then
		echo -e $BCYAN"/**************************************** $WHITE"
		echo -e $BCYAN"|            $BRED TRICHE$BCYAN                     \\"
		echo -ne $BCYAN"| "
		print_error $FUNCT "fonction interdite"
                for MYLINE in `cat $TMP`; do
		    local VAR=`grep -Rwn $FUNCT $MYLINE | grep -vE "#\s*include" | grep -v "$FUNCT\.c"`
		    if [[ ! -z $VAR ]]; then
			local N1VAR=`echo $VAR | awk '{print $1}' | tr ":" " "`
			local N3VAR=`echo $N1VAR | awk '{ print $NF}'`
			echo -ne $BCYAN"| "
			print_error "$MYLINE" "ligne $N3VAR $MAGENTA$FUNCT$WHITE fonction interdite"
		    fi
		done
		echo -e $BCYAN"\                                        /$WHITE"
		echo -e $BCYAN"****************************************$WHITE"
		NB_ERROR=$(($NB_ERROR + 1))
	    elif [[ -z `grep -Fx $FUNCT $ALLOWED` ]]; then
		echo -ne $CYAN$FUNCT" not in allowed functions. Add it (y/n [y]) ? "$WHITE
		read ADDIT
		if [[ -z $ADDIT || $ADDIT = "YES" || $ADDIT = "yes" || $ADDIT = "y" || $ADDIT = "Y" ]]; then
		    echo $FUNCT >> $ALLOWED
		else
		    echo -e "#$FUNCT" >> $ALLOWED
		fi
	    fi
	done
    else
	echo -e $BRED"$PROJECT: file not found or not readable for symbols"$WHITE
    fi
}

function nb_col()
{
    local INDEX=10
    local NB_LINE=`cat $1 | wc -l`
    while [[ $INDEX -le $NB_LINE ]]
    do
	local NB_CARAC=`head $1 -n $INDEX | tail -n 1 | wc -m`
	if [[ $NB_CARAC -gt 81 ]]; then
	    print_error $1 "ligne $INDEX $NB_CARAC caractères"
	    NB_ERROR=$(($NB_ERROR + 1))
	fi
	INDEX=$(($INDEX + 1))
    done
    if [[ ! -z `grep "#define" $1` ]];then
	print_error $1 "ligne `grep -n "#define" $1 | tr ":" " " | awk '{print $1}' | head -n1`, `grep -n "#define" $1 | tr ":" " " | awk '{print $1}' | wc -l` define dans un .c"
	NB_ERROR=$(($NB_ERROR + 1))
    fi
}

function check_include() # verifie l'ordres des  #includes
{
    LINE_D=`grep -n "#include <" $1 | tail -n 1 | tr ':' ' ' | awk '{print $1}'`
    LINE_A=`grep -n "#include \"" $1 | head -n 1 | tr ':' ' ' | awk '{print $1}'`
    if [[ $LINE_A && $LINE_D && $LINE_A < $LINE_D ]]; then
	print_error $1 "include systeme mal placé"
	NB_ERROR=$(($NB_ERROR + 1))
    fi
}

function check_com() # verifie la presence de commentaires
{
    if [[ $COM == 1 ]]
    then
	return
    fi

    tail -n +10 $1 | sed "s/['\"].*['\"]//g" | grep -E "/\*" > $TMP6
    if [[ ! -z `cat $TMP6` ]]
    then
	tail -n +10 $1 > $TMP6
	grep -n "/\*" $TMP6 > $TMP7
	while read ERROR_COM
	do
	     LINE=` echo $ERROR_COM | tr ":" " " | awk '{print $1}'`
	     LINE=$((LINE + 9))
	     print_error $1 "ligne $LINE commentaire dans le code"
	     NB_ERROR=$((NB_ERROR + 1))
	done < $TMP7
    fi
        tail -n +10 $1 | sed "s/['\"].*['\"]//g" | grep -E "//" > $TMP6
    if [[ ! -z `cat $TMP6` ]]
    then
	tail -n +10 $1 | sed "s/['\"].*['\"]//g" > $TMP6
	grep -n "//" $TMP6 > $TMP7
	while read ERROR_COM
	do
	     LINE=` echo $ERROR_COM | tr ":" " " | awk '{print $1}'`
	     LINE=$((LINE + 9))
	     print_error $1 "ligne $LINE commentaire dans le code"
	     NB_ERROR=$((NB_ERROR + 1))
	done < $TMP7
    fi
}

function check_declaration() # verifie les declarations / affectations
{
    grep -nP "\t" $1 | sed "s/['\"].*['\"]//g" | grep -oE ".*=" | grep -v "==" | grep -v "<=" | grep -v ">=" | grep -v "!=" | grep -v "&=" | grep -v "+=" | grep -v "*=" | grep -v "|=" | grep -v "(" | grep -v ")" | grep -v "\->" | grep -v "\-=" | grep -v "static" | sed 's/=//g' > $TMP8
    while read LINE
    do
	if [[ `echo $LINE | wc -w` > 2 ]]; then
	    print_error $1 "ligne `echo $LINE | tr ":" " "| awk '{print $1}'` déclaration et affectation à la même ligne"
	NB_ERROR=$((NB_ERROR + 1))
	fi
    done < $TMP8
}

function last_carac() # verifie les 80 colonnes
{
    local RES=`cat $1 | grep -nE ".*\s+$" | grep -v "*\*" | awk '{print $1}'`
    for LINE in $RES
    do
	print_error $1 "ligne `echo -n $LINE | sed "s/.$//"` espace en fin de ligne"
	NB_ERROR=$((NB_ERROR + 1))
    done
}

function double_line() # verifie les sauts de ligne inutiles
{
    local RES=`pcregrep -Mn "^\n$^\n" $1`
    if [[ -z $RES ]]; then
	return
    fi
    N='\n'
    for INDEX in `echo $RES | tr ':' '\n' | sed 's/ //g'`
    do
	print_error $1 "ligne $INDEX double retour à la ligne"
	INDEX=$(($INDEX + 1))
	NB_ERROR=$((NB_ERROR + 1))
    done
}


function check_mc() # verifie la presence de mot cle interdit
{
    if [[ `cat $1 | grep -n "goto "` ]]; then
	print_error $1 "ligne `cat $1 | grep -n goto | awk '{ print $1}'| tr ':' ' ' | awk '{ print $1}'` utilisation de goto"
	NB_ERROR=$((NB_ERROR + 1))
    fi
    local LIGNE=`cat $1 | grep -v "*" | grep -v "\"" | grep -n for | awk \
       '{ print $1}'| tr ':' ' ' | awk '{ print $1}'`
    if [[ `cat $1 | grep -v "*" | grep -v "\"" | grep -n "for "` ]]; then
	print_error $1 "ligne $LIGNE utilisation de for"
	NB_ERROR=$(($NB_ERROR + 1))
    fi
    if [[ `cat $1 | grep -n "switch "` ]]; then
	print_error $1 "ligne `cat $1 | grep -n switch | awk '{ print $1}'| tr ':' ' ' | awk '{ print $1}'` utilisation de switch"
	NB_ERROR=$((NB_ERROR + 1))
    fi
}

function check_space_op() # verifie les espaces apres les operateurs [+-/*%]
{
    cat $1 | grep -i + | grep -v "++" | grep -v "+=" | grep -v " + " > $TMP10
    if [[ `cat $TMP10` ]]; then
	NBL=`cat $TMP10 |  awk '{print $1}' | sed 's/://g'`
	for NB in $NBL
	do
	    print_error $1 "ligne $NB, il manque un espace autour du \"+\""
	    NB_ERROR=$((NB_ERROR + 1))
	done
    fi
}

function check_multi-instruction() # verifie les multi instructions sur une ligne
{
    local VAL=`cat $1 | grep -En ';.+' | grep -v "';'"| grep -v "\";\"" | awk '{print $1}' | sed "s/.$//" | tr '\n'm ' ' | sed "s/ / , /g"  |  sed 's/...$//'`
    if [[ $VAL ]]; then
	print_error $1 "ligne $VAL multi instruction"
	NB_ERROR=$((NB_ERROR + 1))
    fi
}

function check_space_functions() # verifie les sauts de ligne
{
    cat $1 | grep -nE "^[a-z]{1,}.*\)$" | tr ':' ' ' | awk '{print $1 }' > $TMP10
    for NB_LINE in `cat $TMP10`; do
	NB_LINE=$(($NB_LINE - 1))
	LINE=`head $1 -n $NB_LINE | tail -n1`
	if [[ $LINE ]]; then
	    NB_LINE=$(($NB_LINE + 1))
	    print_error $1 "ligne $NB_LINE, il manque un saut de ligne"
	    NB_ERROR=$((NB_ERROR + 1))
	fi
    done
}

function check_tab_on_declaraction() # verifie les tabs dans les declaractions
{
    cat $1 | grep -nE "^[a-z]{1,}.*\)$" | tr ':' ' ' | awk '{print $1 }' > $TMP16
    for NB_LINE in `cat $TMP16`; do
	NB_LINE=$(($NB_LINE + 2))
	while [[ `head $1 -n $NB_LINE | tail -n1` && $NB_LINE < `wc -l $1` ]]; do
	    LINE=`head $1 -n $NB_LINE | tail -n1`
	    local WORD=`echo $LINE | awk '{print $1 }'`
	    if [[ `head $1 -n $NB_LINE | tail -n1 | grep -P $WORD" "` &&
			`echo grep -v '"' $LINE | grep -v "(" | grep -v '{' | grep -v '}' | grep -v "else" | grep -v while` ]]; then
		print_error $1 "ligne $NB_LINE, il manque une tabulation (alt + i)"
		NB_ERROR=$((NB_ERROR + 1))
	    fi
	    NB_LINE=$(($NB_LINE + 1))
	done
    done
}

function check_line_declaration() # verifie les sauts de ligne apres les declarations
{
    cat $1 | grep -nE "^[a-z]{1,}.*\)$" | tr ':' ' ' | awk '{print $1 }' > $TMP10
    for NB_LINE in `cat $TMP10`; do
	NB_LINE=$(($NB_LINE + 2))
	while [[ `head $1 -n $NB_LINE | tail -n1 |grep -v '"' | grep -v "(" | grep -v "=" | grep -v '{' | grep -v '}' | grep -v "else" | grep -v while` ]]; do
	    NB_LINE=$(($NB_LINE + 1))
	done
	LINE=`head $1 -n $NB_LINE | tail -n1`
	local VAL=$(($NB_LINE - 1))
	if [[ `head $1 -n $VAL | tail -n1` != "{" && $LINE  ]]; then
	    NB_LINE=$(($NB_LINE + 1))
	    print_error $1 "ligne $NB_LINE, il manque un saut de ligne"
	    NB_ERROR=$((NB_ERROR + 1))
	fi
    done
}

function check_malloc() # verifie les mallocs
{
    if [[ $MALLOC == 1 ]]
    then
	return
    fi

    cat $1 | grep -n malloc | grep -v if | grep -v NULL | grep -iv xmalloc | grep -v "||"> $TMP5
    if [[ `cat $TMP5` ]]; then
	NBL=`cat $TMP5 |  awk '{print $1}' | sed 's/://g'`
	for NB in $NBL
	do
	    print_error $1 "ligne $NB, malloc non verifié"
	    NB_ERROR=$((NB_ERROR + 1))
	done
    fi
}

function check_var_name() # verifie le noms des variables
{
    # GLOBALS
    cat $1 | grep -nE "^[a-z]{1,}.*\)$" | tr ':' ' ' | awk '{print $1 }' | grep "#" | head -n1 > $TMP11
    local NBF=`cat $TMP11`
    if [[ -z $NBF ]]; then
	return
    fi
    NBF=$((NBF - 1))
    local NB=10
    while [[ $NB -ne $NBF ]]; do
	NB=$((NB + 1))
	if [[ `head $1 -n $NB | tail -n1 | grep -v '#' | grep "\*"| grep -v "g_"` ]]; then
	    head $1 -n $NB | tail -n -1
	    print_error $1 "ligne $NB, il manque \"g_\" au nom de la variable"
	    NB_ERROR=$((NB_ERROR + 1))
	fi
    done
    # LES AUTRES
    cat $1 | grep -nE "^[a-z]{1,}.*\)$" | tr ':' ' ' | awk '{print $1 }' > $TMP15
    for NB_LINE in `cat $TMP10`; do
	NB_LINE=$(($NB_LINE + 2))
	while [[ `head $1 -n $NB_LINE | tail -n1 |grep -v '"' | grep -v "(" | grep -v "=" | grep -v '{' | grep -v '}' | grep -v "+" | grep -v "-" | grep -v "else"` ]]; do
	    LINE=`head $1 -n $NB_LINE | tail -n1`
	    NB_LINE=$(($NB_LINE + 1))
	    if [[ $LINE && `echo $LINE | grep -v char | grep -v int | grep -v void | grep -v long | grep -v double | grep -v "_"` ]]; then
		local NB=$(($NB_LINE - 1))
		print_error $1 "ligne $NB, nom de la variable incorrect "
		NB_ERROR=$((NB_ERROR + 1))
	    fi
	done
    done
}

function test_conf_dir() # test la presence du fichier $HOME/.config/norme
{
    if [[ -d $HOME/.config/norme ]]; then
	mkdir -p $HOME/.config/norme
    fi
}

function presentation() # affiche le message d'info
{
    echo -e "Moulinette de norme epitech par armita_a et de-dum_m\n"
    echo -e "Executer dans le repertoire principal, de preference en"
    echo -e "présence d'un Makefile et d'un executable.\n"
    echo -e "Géré:"
    echo -e " ➜ fonctions de plus de 25 lignes"
    echo -e " ➜ mauvais header"
    echo -e " ➜ fonctions autorisées/interdites"
    echo -e " ➜ nombre de fonctions par fichier"
    echo -e " ➜ espace manquant après mot clef"
    echo -e " ➜ double retour à la ligne"
    echo -e " ➜ ligne de plus de 80 caractères"
    echo -e " ➜ plus de 4 paramètres pour une fonction"
    echo -e " ➜ commentaire dans le code"
    echo -e " ➜ ordonnencement des include"
    echo -e " ➜ declaration et affectation sur la même ligne"
    echo -e " ➜ saut de ligne après les déclarations"
    echo -e " ➜ protection headers"
    echo -e " ➜ multi-instruction"
    echo -e " ➜ define dans un .c"
    echo -e " ➜ norme Makefile"
    echo -e " ➜ espace en fin de ligne"
    echo -e " ➜ nom des variables et structures"
    echo -e " ➜ tabulation dans les déclarations"
    echo -e " ➜ retour a la ligne manquant entre deux fonctions"
    echo -e " ➜ saut de ligne après les déclarations\n"
    echo -e "Sauvergarde les fonctions autorisées dans le repertoire:"
    echo -e "$HOME/.config/norme\n"
    usage
}

function usage() # affiche le usage
{
    echo -e "options:"
    echo -e "-h	--help		afficher ce message"
    echo -e "-c	--no-colors	desactiver les couleurs"
    echo -e "-u	--users         permet d'ajouter des participants au projet"
    echo -e "-M	--makefile      activer la verification du Makefile"
    echo -e "-m	--malloc        desactiver la verification des mallocs"
    echo -e "-C	--comment        desactiver la verification des commentaire"
    echo -e "-R	--reset		oublier les fonctions autorisées"
    exit 0
}

function options() # verifie les options
{
    while [[ $# -gt 0 ]]; do
	if [[ $1 == "--no-colors" || $ARG == "-c" ]]; then
	    WHITE="\033[0m"
	    RED="\033[0m"
	    GREEN="\033[0m"
	    YELLOW="\033[0m"
	    BLUE="\033[0m"
	    MAGENTA="\033[0m"
	    CYAN="\033[0m"
	    BOLD="\033[0m"
	    BRED="\033[0m"
	    BGREEN="\033[0m"
	    BYELLOW="\033[0m"
	    BBLUE="\033[0m"
	    BMAGENTA="\033[0m"
	    BCYAN="\033[0m"
	elif [[ $1 == "-R" || $1 == "--reset" ]]; then
	    rm -f $ALLOWED
	    rm -f $ALLOWED_U
	    exit 0
	elif [[ $1 == "-h" || $1 == "--help" ]]; then
	    presentation
	elif [[ $1 == "-m" || $1 == "--malloc" ]]; then
	    MALLOC=1
	elif [[ $1 == "-M" || $1 == "--makefile" ]]; then
	    CM=1
	elif [[ $1 == "-C" || $1 == "--comment" ]]; then
	    COM=1
	elif [[ $1 == "-u" || $1 == "--users" ]]; then
	    shift
	    while [[ $# -gt 0 ]]; do
		echo $1 >> $ALLOWED_U
		shift
	    done
	    exit 0
	else
	    usage
	fi
	shift
    done
}

clear
options $*

if [[ -z $PROJECT ]]; then
    PROJECT=$(rlwrap -c -S "Executable name: " -o cat)
fi

if [[ ! -d $HOME/.config/norme ]]; then
    mkdir -p $HOME/.config/norme
fi

if [[ ! -d $HOME/.config/norme/.temp ]]; then
    mkdir -p $FTEMP
fi

if [[ ! -f $ALLOWED ]]; then
    touch $ALLOWED
fi

if [[ ! -f $ALLOWED_U ]]; then
    echo $USER > $ALLOWED_U
fi

find $PWD -name "*.c" | grep -v \# > $TMP

for SFILE in `cat $TMP`; do
    echo -e "Scan : "$BOLD"`basename $SFILE`"$WHITE
    nb_functions $SFILE
    check_header $SFILE
    nb_col $SFILE
    last_carac $SFILE
    double_line $SFILE
    keyword_spaces $SFILE
    function_length $SFILE
    function_params $SFILE
    check_com $SFILE
    check_mc $SFILE
    check_include $SFILE
    check_declaration $SFILE
    check_multi-instruction $SFILE
#    check_tab_on_declaraction $SFILE
    check_space_functions $SFILE
    check_line_declaration $SFILE
    check_var_name $SFILE
    check_malloc $SFILE
 #  check_space_op $SFILE
done

dot_h
allowed_functions

if [[ $CM -eq 1 ]]; then
    check_makefile
fi

if [[ $NB_ERROR -eq 0 ]]; then
    echo -e $BGREEN"Vous avez fait 0 fautes de norme"
elif [[ $NB_ERROR -eq 1 ]]; then
    echo -e $BRED"Vous avez fait $NB_ERROR faute de norme."
else
    echo -e $BRED"Vous avez fait $NB_ERROR fautes de norme."
fi
echo -ne $WHITE
rm -rf $FTEMP
