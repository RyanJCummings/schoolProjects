import java.util.Arrays;

public class KVArray {
    /* Arrays.copyOf() */
    KeyValue [] table;

    public KVArray(){
        table = new KeyValue[5];
    }

    /* maps key-value pairs to hash table */
    public void hashMap(KeyValue pair){
        int ObjLength = nonNullLength(table);
        int index = pair.getKey() % table.length;

        while(table[index] != null){
            if ((double)ObjLength / (double)table.length >= .80) {
                table = resize(table);
            }
            if (index + 2 < table.length) {
                index++;
            }
            else {
                index = 0;
            }
        }
        table[index] = pair;
        printTable(table);
    }

    /* doubles size of Key-Value Array when load factor reaches 80% */
    public KeyValue[] resize(KeyValue[] hashTable){

        KeyValue[] doubledArray;

        doubledArray = Arrays.copyOf(hashTable, hashTable.length * 2);
        rehash(doubledArray);
        return doubledArray;
    }


    /* rehashes table after array resize */
    public void rehash(KeyValue[] hashTable){
        for (KeyValue i: hashTable){
           hashMap(i);
        }
    }

    /* Determines number of non_null elements in key-value array */
    public int nonNullLength(KeyValue[] pairArr) {
        int length = 0;
         for (KeyValue i : pairArr){
            if (i != null){
                length++;
            }
        }
        return length;
    }
    /* prints hash table to console */
    public void printTable(KeyValue[] hashTable){
        for (int i = 0; i < hashTable.length; i++) {
            System.out.println(hashTable[i]);
        }
    }
}
