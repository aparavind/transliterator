<?php 

/**
 * This is a simple php program which converts a csv file to struct class
 * 
 */

/**
    This is a simple code which converts csv to a c struct along with data
    first column induvidual name
    second column type
**/

$ifile_name = $argv[1];
$fi = fopen($ifile_name,"r");
if (!$fi){
    print "unable to open input file $file_name\n";
    exit(1);
}


$arr = pathinfo($ifile_name);
$struct_name = $arr["filename"];

$outHeaderFileName = $arr["dirname"] . "/../" . $struct_name . ".h";
$outCFileName = $arr["dirname"] . "/../" . $struct_name.".c";

$fh = fopen($outHeaderFileName,"w");
if (!$fh){
    print "Error unable to open file $outHeaderFileName for writing";
    exit;
}

$fc = fopen($outCFileName,"w");
if (!$fc){
    print "Error unable to open file $outCFileName for writing";
    exit;
}


// getting the headers
$elements = fgetcsv($fi);

print "Elements are " ; print_r($elements);

$i = 0;
$maxlen = array();
foreach ($elements as $ele){
    list($field_name[$i],$field_type[$i]) = str_getcsv($ele);
    $maxlen[$i] = 0;
    $i++;
}
print "the Headers are " ; print_r($field_name);
print "the header types are " ; print_r($field_type);
print "the no of columns are  $i\n";
$k = 0;
$out_array = array();

while ($content = fgetcsv($fi)){
    $out_array[$k] = array();
    for ($j = 0; $j < $i ; $j++){
        switch ($field_type[$j]){
            case "char[]" :
                $llen = strlen($content[$j]);
                if ($llen > $maxlen[$j]){
                    $maxlen[$j] = $llen;
                }
                $out_array[$k][$j] = '"' . $content[$j] . '"';
                break;
            case "int" :
                    $out_array[$k][$j] = $content[$j];
                    break;
        }
    }
    $k++;
}
$elems = $k;

// push the defination of struct in .h file
$defStr = "typedef struct $struct_name {\n[%% struct %%]\n} $struct_name;";
$struct = "";
for ($j = 0; $j < $i ; $j++){
    switch ($field_type[$j]){
        case "char[]" :
            $struct .= "\tchar {$field_name[$j]}[" . ($maxlen[$j] + 1) . "];\n";
            break;
        default :
            $struct .= "\t{$field_type[$j]} {$field_name[$j]};\n";
            break;
    }
}
$defStr = str_replace('[%% struct %%]',$struct,$defStr);

print "ENTERED WORDS Are $elems";
$arrStr = "$struct_name {$struct_name}_array[ENTERED_WORDS] = {\n"; 

for ($j = 0 ; $j < $elems ; $j ++){
    if ($j){
        $arrStr .= ",";
    }
    $arrStr = $arrStr . "\n\t{" . implode(",",$out_array[$j]) . "}";
}
$arrStr .= "\n};";

##print $arrStr ; 

// creation of Header file
fwrite($fh,"#ifndef " . strtoupper($struct_name) . "_H_INCLUDED\n");
fwrite($fh,"#define " . strtoupper($struct_name) . "_H_INCLUDED\n\n");
fwrite($fh,"#define " . "ENTERED_WORDS $elems \n\n");
fwrite($fh,$defStr . "\n\n");
fwrite($fh,"extern $struct_name {$struct_name}_array[ENTERED_WORDS];\n\n");
fwrite($fh,"#endif");
fclose($fh);

fwrite($fc,"#include \"{$struct_name}.h\"\n\n");
fwrite($fc,$arrStr);
fclose($fc);

