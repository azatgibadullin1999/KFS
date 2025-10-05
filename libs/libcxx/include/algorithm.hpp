#ifndef _LIBCPP_ALGORITHM
# define _LIBCPP_ALGORITHM

# include<__algorithm/find_first_not_of_own.hpp>

# include<__algorithm/adjacent_find.h>
# include<__algorithm/all_of.h>
# include<__algorithm/any_of.h>
// # include<__algorithm/binary_search.h>
# include<__algorithm/clamp.h>
# include<__algorithm/comp.h>
# include<__algorithm/comp_ref_type.h>
# include<__algorithm/copy.h>
# include<__algorithm/copy_backward.h>
# include<__algorithm/copy_if.h>
// # include<__algorithm/copy_move_common.h>
// # include<__algorithm/copy_n.h>
// # include<__algorithm/count.h>
# include<__algorithm/count_if.h>
# include<__algorithm/equal.h>
# include<__algorithm/equal_range.h>
# include<__algorithm/fill.h>
# include<__algorithm/fill_n.h>
# include<__algorithm/find.h>
# include<__algorithm/find_end.h>
# include<__algorithm/find_first_of.h>
# include<__algorithm/find_if.h>
# include<__algorithm/find_if_not.h>
# include<__algorithm/find_segment_if.h>
// # include<__algorithm/fold.h>
// # include<__algorithm/for_each.h>
# include<__algorithm/for_each_n.h>
# include<__algorithm/for_each_segment.h>
# include<__algorithm/generate.h>
# include<__algorithm/generate_n.h>
# include<__algorithm/half_positive.h>
# include<__algorithm/in_found_result.h>
# include<__algorithm/in_fun_result.h>
# include<__algorithm/in_in_out_result.h>
# include<__algorithm/in_in_result.h>
# include<__algorithm/in_out_out_result.h>
# include<__algorithm/in_out_result.h>
// # include<__algorithm/includes.h>
// # include<__algorithm/inplace_merge.h>
# include<__algorithm/is_heap.h>
# include<__algorithm/is_heap_until.h>
# include<__algorithm/is_partitioned.h>
// # include<__algorithm/is_permutation.h>
# include<__algorithm/is_sorted.h>
# include<__algorithm/is_sorted_until.h>
# include<__algorithm/iter_swap.h>
# include<__algorithm/iterator_operations.h>
# include<__algorithm/lexicographical_compare.h>
// # include<__algorithm/lexicographical_compare_three_way.h>
// # include<__algorithm/lower_bound.h>
# include<__algorithm/make_heap.h>
// # include<__algorithm/make_projected.h>
# include<__algorithm/max.h>
# include<__algorithm/max_element.h>
// # include<__algorithm/merge.h>
# include<__algorithm/min.h>
// # include<__algorithm/min_element.h>
# include<__algorithm/min_max_result.h>
// # include<__algorithm/minmax.h>
// # include<__algorithm/minmax_element.h>
# include<__algorithm/mismatch.h>
// # include<__algorithm/move.h>
# include<__algorithm/move_backward.h>
# include<__algorithm/next_permutation.h>
# include<__algorithm/none_of.h>
// # include<__algorithm/nth_element.h>
// # include<__algorithm/partial_sort.h>
// # include<__algorithm/partial_sort_copy.h>
# include<__algorithm/partition.h>
# include<__algorithm/partition_copy.h>
# include<__algorithm/partition_point.h>
# include<__algorithm/pop_heap.h>
# include<__algorithm/prev_permutation.h>
// # include<__algorithm/pstl_any_all_none_of.h>
// # include<__algorithm/pstl_backend.h>
// # include<__algorithm/pstl_copy.h>
// # include<__algorithm/pstl_count.h>
// # include<__algorithm/pstl_equal.h>
// # include<__algorithm/pstl_fill.h>
// # include<__algorithm/pstl_find.h>
// # include<__algorithm/pstl_for_each.h>
# include<__algorithm/pstl_frontend_dispatch.h>
// # include<__algorithm/pstl_generate.h>
// # include<__algorithm/pstl_is_partitioned.h>
// # include<__algorithm/pstl_merge.h>
// # include<__algorithm/pstl_move.h>
// # include<__algorithm/pstl_replace.h>
// # include<__algorithm/pstl_rotate_copy.h>
// # include<__algorithm/pstl_sort.h>
// # include<__algorithm/pstl_stable_sort.h>
// # include<__algorithm/pstl_transform.h>
# include<__algorithm/push_heap.h>
# include<__algorithm/ranges_adjacent_find.h>
# include<__algorithm/ranges_all_of.h>
# include<__algorithm/ranges_any_of.h>
# include<__algorithm/ranges_binary_search.h>
# include<__algorithm/ranges_clamp.h>
# include<__algorithm/ranges_contains.h>
# include<__algorithm/ranges_copy.h>
# include<__algorithm/ranges_copy_backward.h>
# include<__algorithm/ranges_copy_if.h>
# include<__algorithm/ranges_copy_n.h>
# include<__algorithm/ranges_count.h>
# include<__algorithm/ranges_count_if.h>
# include<__algorithm/ranges_ends_with.h>
# include<__algorithm/ranges_equal.h>
# include<__algorithm/ranges_equal_range.h>
# include<__algorithm/ranges_fill.h>
# include<__algorithm/ranges_fill_n.h>
# include<__algorithm/ranges_find.h>
# include<__algorithm/ranges_find_end.h>
# include<__algorithm/ranges_find_first_of.h>
# include<__algorithm/ranges_find_if.h>
# include<__algorithm/ranges_find_if_not.h>
# include<__algorithm/ranges_for_each.h>
# include<__algorithm/ranges_for_each_n.h>
# include<__algorithm/ranges_generate.h>
# include<__algorithm/ranges_generate_n.h>
# include<__algorithm/ranges_includes.h>
# include<__algorithm/ranges_inplace_merge.h>
# include<__algorithm/ranges_is_heap.h>
# include<__algorithm/ranges_is_heap_until.h>
# include<__algorithm/ranges_is_partitioned.h>
# include<__algorithm/ranges_is_permutation.h>
# include<__algorithm/ranges_is_sorted.h>
# include<__algorithm/ranges_is_sorted_until.h>
# include<__algorithm/ranges_iterator_concept.h>
# include<__algorithm/ranges_lexicographical_compare.h>
# include<__algorithm/ranges_lower_bound.h>
# include<__algorithm/ranges_make_heap.h>
# include<__algorithm/ranges_max.h>
# include<__algorithm/ranges_max_element.h>
# include<__algorithm/ranges_merge.h>
# include<__algorithm/ranges_min.h>
# include<__algorithm/ranges_min_element.h>
# include<__algorithm/ranges_minmax.h>
# include<__algorithm/ranges_minmax_element.h>
# include<__algorithm/ranges_mismatch.h>
# include<__algorithm/ranges_move.h>
# include<__algorithm/ranges_move_backward.h>
# include<__algorithm/ranges_next_permutation.h>
# include<__algorithm/ranges_none_of.h>
// # include<__algorithm/ranges_nth_element.h>
// # include<__algorithm/ranges_partial_sort.h>
// # include<__algorithm/ranges_partial_sort_copy.h>
# include<__algorithm/ranges_partition.h>
# include<__algorithm/ranges_partition_copy.h>
# include<__algorithm/ranges_partition_point.h>
# include<__algorithm/ranges_pop_heap.h>
# include<__algorithm/ranges_prev_permutation.h>
# include<__algorithm/ranges_push_heap.h>
# include<__algorithm/ranges_remove.h>
# include<__algorithm/ranges_remove_copy.h>
# include<__algorithm/ranges_remove_copy_if.h>
# include<__algorithm/ranges_remove_if.h>
# include<__algorithm/ranges_replace.h>
# include<__algorithm/ranges_replace_copy.h>
# include<__algorithm/ranges_replace_copy_if.h>
# include<__algorithm/ranges_replace_if.h>
# include<__algorithm/ranges_reverse.h>
# include<__algorithm/ranges_reverse_copy.h>
# include<__algorithm/ranges_rotate.h>
# include<__algorithm/ranges_rotate_copy.h>
// # include<__algorithm/ranges_sample.h>
# include<__algorithm/ranges_search.h>
# include<__algorithm/ranges_search_n.h>
# include<__algorithm/ranges_set_difference.h>
# include<__algorithm/ranges_set_intersection.h>
# include<__algorithm/ranges_set_symmetric_difference.h>
# include<__algorithm/ranges_set_union.h>
// # include<__algorithm/ranges_shuffle.h>
// # include<__algorithm/ranges_sort.h>
// # include<__algorithm/ranges_sort_heap.h>
# include<__algorithm/ranges_stable_partition.h>
// # include<__algorithm/ranges_stable_sort.h>
# include<__algorithm/ranges_starts_with.h>
# include<__algorithm/ranges_swap_ranges.h>
# include<__algorithm/ranges_transform.h>
# include<__algorithm/ranges_unique.h>
# include<__algorithm/ranges_unique_copy.h>
# include<__algorithm/ranges_upper_bound.h>
// # include<__algorithm/remove.h>
# include<__algorithm/remove_copy.h>
# include<__algorithm/remove_copy_if.h>
# include<__algorithm/remove_if.h>
# include<__algorithm/replace.h>
# include<__algorithm/replace_copy.h>
# include<__algorithm/replace_copy_if.h>
# include<__algorithm/replace_if.h>
# include<__algorithm/reverse.h>
# include<__algorithm/reverse_copy.h>
# include<__algorithm/rotate.h>
# include<__algorithm/rotate_copy.h>
// # include<__algorithm/sample.h>
// # include<__algorithm/search.h>
// # include<__algorithm/search_n.h>
// # include<__algorithm/set_difference.h>
# include<__algorithm/set_intersection.h>
# include<__algorithm/set_symmetric_difference.h>
# include<__algorithm/set_union.h>
# include<__algorithm/shift_left.h>
# include<__algorithm/shift_right.h>
// # include<__algorithm/shuffle.h>
# include<__algorithm/sift_down.h>
// # include<__algorithm/sort.h>
// # include<__algorithm/sort_heap.h>
// # include<__algorithm/stable_partition.h>
// # include<__algorithm/stable_sort.h>
# include<__algorithm/swap_ranges.h>
# include<__algorithm/three_way_comp_ref_type.h>
# include<__algorithm/transform.h>
# include<__algorithm/uniform_random_bit_generator_adaptor.h>
# include<__algorithm/unique.h>
# include<__algorithm/unique_copy.h>
# include<__algorithm/unwrap_iter.h>
# include<__algorithm/unwrap_range.h>
// # include<__algorithm/upper_bound.h>

#endif // _LIBCPP_ALGORITHM
