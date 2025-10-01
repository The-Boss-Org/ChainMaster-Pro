#include <stdio.h>
#include <stdlib.h>
#include "../../include/chainmaster.h"

// Simple test framework
int tests_passed = 0;
int tests_failed = 0;

#define TEST(name) void name()
#define ASSERT(cond, msg) if (!(cond)) { \
    printf("❌ FAIL: %s - %s\n", __func__, msg); \
    tests_failed++; \
    return; \
} else { tests_passed++; }

#define RUN_TEST(test) printf("Running %s...\n", #test); test();

// ===== Tests Exercice 1 =====
TEST(test_sll_delete_all_empty) {
    SNode* list = NULL;
    list = sll_delete_all(list, 5);
    ASSERT(list == NULL, "Delete from empty list should return NULL");
}

TEST(test_sll_delete_all_single) {
    SNode* list = NULL;
    list = sll_insert_sorted(list, 5);
    list = sll_delete_all(list, 5);
    ASSERT(list == NULL, "Delete only element should return NULL");
}

TEST(test_sll_delete_all_multiple) {
    SNode* list = NULL;
    list = sll_insert_sorted(list, 3);
    list = sll_insert_sorted(list, 3);
    list = sll_insert_sorted(list, 5);
    list = sll_delete_all(list, 3);
    ASSERT(list != NULL && list->data == 5, "Should keep non-deleted elements");
}

// ===== Tests Exercice 2 =====
TEST(test_sll_insert_sorted_empty) {
    SNode* list = NULL;
    list = sll_insert_sorted(list, 10);
    ASSERT(list != NULL && list->data == 10, "Insert in empty list");
}

TEST(test_sll_insert_sorted_order) {
    SNode* list = NULL;
    list = sll_insert_sorted(list, 5);
    list = sll_insert_sorted(list, 2);
    list = sll_insert_sorted(list, 8);
    ASSERT(list->data == 2 && list->next->data == 5, "Should maintain order");
}

// ===== Tests Exercice 3 =====
TEST(test_dll_insert_sorted_empty) {
    DList* list = NULL;
    list = dll_insert_sorted(list, 10);
    ASSERT(list != NULL && list->data == 10, "DLL insert in empty");
}

TEST(test_dll_insert_sorted_order) {
    DList* list = NULL;
    list = dll_insert_sorted(list, 5);
    list = dll_insert_sorted(list, 2);
    ASSERT(list->data == 2 && list->next->data == 5, "DLL should maintain order");
}

// ===== Tests Exercice 4 =====
TEST(test_cll_insert_head) {
    Node* cll = cll_create();
    cll = cll_insert_head(cll, 10);
    ASSERT(cll != NULL && cll->data == 10, "CLL insert head");
    cll_free(cll);
}

TEST(test_cll_insert_tail) {
    Node* cll = cll_create();
    cll = cll_insert_tail(cll, 10);
    ASSERT(cll != NULL && cll->data == 10, "CLL insert tail");
    cll_free(cll);
}

// ===== Tests Exercice 5 =====
TEST(test_cdll_insert_head) {
    DNode* cdll = cdll_create();
    cdll = cdll_insert_head(cdll, 10);
    ASSERT(cdll != NULL && cdll->data == 10, "CDLL insert head");
    cdll_free(cdll);
}

TEST(test_cdll_insert_tail) {
    DNode* cdll = cdll_create();
    cdll = cdll_insert_tail(cdll, 10);
    ASSERT(cdll != NULL && cdll->data == 10, "CDLL insert tail");
    cdll_free(cdll);
}

TEST(test_cdll_circularity) {
    DNode* cdll = cdll_create();
    cdll = cdll_insert_head(cdll, 10);
    cdll = cdll_insert_tail(cdll, 20);
    ASSERT(cdll->prev->next == cdll, "CDLL should be circular");
    cdll_free(cdll);
}

int main(void) {
    printf("\n🧪 ChainMaster Pro - Test Suite\n");
    printf("================================\n\n");

    printf("📋 Exercice 1 - Delete All Occurrences:\n");
    RUN_TEST(test_sll_delete_all_empty);
    RUN_TEST(test_sll_delete_all_single);
    RUN_TEST(test_sll_delete_all_multiple);

    printf("\n📋 Exercice 2 - Sorted Insert (Simple):\n");
    RUN_TEST(test_sll_insert_sorted_empty);
    RUN_TEST(test_sll_insert_sorted_order);

    printf("\n📋 Exercice 3 - Sorted Insert (Double):\n");
    RUN_TEST(test_dll_insert_sorted_empty);
    RUN_TEST(test_dll_insert_sorted_order);

    printf("\n📋 Exercice 4 - Circular Simple List:\n");
    RUN_TEST(test_cll_insert_head);
    RUN_TEST(test_cll_insert_tail);

    printf("\n📋 Exercice 5 - Circular Double List:\n");
    RUN_TEST(test_cdll_insert_head);
    RUN_TEST(test_cdll_insert_tail);
    RUN_TEST(test_cdll_circularity);

    printf("\n================================\n");
    printf("✅ Tests Passed: %d\n", tests_passed);
    printf("❌ Tests Failed: %d\n", tests_failed);
    printf("📊 Success Rate: %.1f%%\n", 
           (100.0 * tests_passed) / (tests_passed + tests_failed));

    return tests_failed > 0 ? 1 : 0;
}
